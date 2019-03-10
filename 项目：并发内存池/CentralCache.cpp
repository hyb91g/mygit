#include "CentralCache.h"
#include "PageCache.h"
CentralCache CentralCache::_inst;


//// 打桩
//// 从中心缓存获取一定数量的对象给thread cache
//size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t n, size_t bytes)
//{
//	start = malloc(bytes * n);
//	end = (char*)start + bytes*(n-1);
//
//	void* cur = start;
//	while (cur <= end)
//	{
//		void* next = (char*)cur + bytes;
//		OBJ_NEXT(cur) = next;
//		
//		cur = next;
//	}
//
//	OBJ_NEXT(end) = nullptr;
//
//	return n;
//}


//找到对应的SpanList链表中可用的span
Span* CentralCache::GetOneSpan(SpanList* spanlist, size_t bytes)
{
	Span* span = spanlist->Begin();
	while (span != spanlist->End())
	{
		if (span->_list != nullptr)
		{
			return span;
		}
		span = span->_next;
	}
	// 走到这里表示没有合适span
	// 向pagecache申请一个新的合适大小的span
	size_t npage = ClassSize::NumMovePage(bytes);    //计算一次获取几个页
	Span* newspan = PageCache::GetInstance()->NewSpan(npage);

	// 将span的内存切割成一个个bytes大小的对象挂起来
	char* start = (char*)(newspan->_pageid << PAGE_SHIFT);
	char* end = start + (newspan->_npage << PAGE_SHIFT);

	char* cur = start;
	char* next = cur + bytes;
	while (next < end)
	{
		OBJ_NEXT(cur) = next;
		cur = next;
		next = cur + bytes;
	}
	OBJ_NEXT(cur) = nullptr;
	newspan->_list = start;
	newspan->_objsize = bytes;
	newspan->_usecount = 0;
	// 将newspan插入到spanlist
	spanlist->PushFront(newspan);
	return newspan;
}

//从中心缓存拿一定数量的内存给线程缓存
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t bytes)
{
	size_t index = ClassSize::Index(bytes);
	SpanList& spanlist = _spfreelist[index];

	//对当前桶进行加锁
	std::unique_lock<std::mutex> lock(spanlist._mutex);

	Span* span = GetOneSpan(&spanlist, bytes); // 找到index对应的SpanList链表中可用的span
	
	//从span中拿num个对象
	void* cur = span->_list;
	void* prev = nullptr;
	size_t fetchnum = 0;
	while (cur != nullptr && fetchnum < num)  //span中自由链表中的小块个数可能比num多,也可能比num少
	{
		++fetchnum;
		prev = cur;
		cur = OBJ_NEXT(cur);
	}

	start = span->_list;
	end = prev;
	OBJ_NEXT(end) = nullptr;

	span->_list = cur;
	span->_usecount += fetchnum;

	//当一个span为空，将span移到尾上
	if (span->_list == nullptr)
	{
		spanlist.Erase(span);
		spanlist.PushBack(span);
	}

	return fetchnum;
}

//将一定数量的对象释放到span跨度
void CentralCache::ReleaseListToSpans(void* start, size_t index)
{
	SpanList& spanlist = _spfreelist[index];
	
	std::unique_lock<std::mutex> lock(spanlist._mutex);

	//先找到每个对象对应的span,对每一个对象进行头插
	while (start)
	{
		void *next = OBJ_NEXT(start);
		Span* span = PageCache::GetInstance()->MapObjectToSpan(start);  // 按地址找到对应的span
		//当释放的对象回到空的span,就将他拿到前边去
		if (span->_list == nullptr)
		{
			spanlist.Erase(span);
			spanlist.PushFront(span);
		}

		//对每个对象进行头插
		OBJ_NEXT(start) = span->_list;
		span->_list = start;

		//_usecount == 0表示span切出去的对象都还回来了
		//释放span回到pagecahce进行合并
		if (--span->_usecount == 0)
		{
			spanlist.Erase(span);  //从链表中删除对应的span

			span->_list = nullptr; 
			span->_objsize = 0;
			span->_prev = nullptr;
			span->_next = nullptr;

			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		}

		start = next;
	}
}
