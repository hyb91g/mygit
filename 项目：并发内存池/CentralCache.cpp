#include "CentralCache.h"
#include "PageCache.h"
CentralCache CentralCache::_inst;


//// ��׮
//// �����Ļ����ȡһ�������Ķ����thread cache
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


//�ҵ���Ӧ��SpanList�����п��õ�span
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
	// �ߵ������ʾû�к���span
	// ��pagecache����һ���µĺ��ʴ�С��span
	size_t npage = ClassSize::NumMovePage(bytes);    //����һ�λ�ȡ����ҳ
	Span* newspan = PageCache::GetInstance()->NewSpan(npage);

	// ��span���ڴ��и��һ����bytes��С�Ķ��������
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
	// ��newspan���뵽spanlist
	spanlist->PushFront(newspan);
	return newspan;
}

//�����Ļ�����һ���������ڴ���̻߳���
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t bytes)
{
	size_t index = ClassSize::Index(bytes);
	SpanList& spanlist = _spfreelist[index];

	//�Ե�ǰͰ���м���
	std::unique_lock<std::mutex> lock(spanlist._mutex);

	Span* span = GetOneSpan(&spanlist, bytes); // �ҵ�index��Ӧ��SpanList�����п��õ�span
	
	//��span����num������
	void* cur = span->_list;
	void* prev = nullptr;
	size_t fetchnum = 0;
	while (cur != nullptr && fetchnum < num)  //span�����������е�С��������ܱ�num��,Ҳ���ܱ�num��
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

	//��һ��spanΪ�գ���span�Ƶ�β��
	if (span->_list == nullptr)
	{
		spanlist.Erase(span);
		spanlist.PushBack(span);
	}

	return fetchnum;
}

//��һ�������Ķ����ͷŵ�span���
void CentralCache::ReleaseListToSpans(void* start, size_t index)
{
	SpanList& spanlist = _spfreelist[index];
	
	std::unique_lock<std::mutex> lock(spanlist._mutex);

	//���ҵ�ÿ�������Ӧ��span,��ÿһ���������ͷ��
	while (start)
	{
		void *next = OBJ_NEXT(start);
		Span* span = PageCache::GetInstance()->MapObjectToSpan(start);  // ����ַ�ҵ���Ӧ��span
		//���ͷŵĶ���ص��յ�span,�ͽ����õ�ǰ��ȥ
		if (span->_list == nullptr)
		{
			spanlist.Erase(span);
			spanlist.PushFront(span);
		}

		//��ÿ���������ͷ��
		OBJ_NEXT(start) = span->_list;
		span->_list = start;

		//_usecount == 0��ʾspan�г�ȥ�Ķ��󶼻�������
		//�ͷ�span�ص�pagecahce���кϲ�
		if (--span->_usecount == 0)
		{
			spanlist.Erase(span);  //��������ɾ����Ӧ��span

			span->_list = nullptr; 
			span->_objsize = 0;
			span->_prev = nullptr;
			span->_next = nullptr;

			PageCache::GetInstance()->ReleaseSpanToPageCache(span);
		}

		start = next;
	}
}
