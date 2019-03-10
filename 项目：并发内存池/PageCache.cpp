#include"PageCache.h"

PageCache PageCache::_inst;

//获取从对象到span的映射：根据对象地址获取
Span* PageCache::MapObjectToSpan(void* obj)
{
	PageID pageid = (PageID)obj >> PAGE_SHIFT;
	auto it = _id_span_map.find(pageid);
	assert(it != _id_span_map.end());

	return it->second;
}


//1、中心缓存不够时，向页缓存中拿出一块新的span
//2、线程缓存需要的对象大于64k时，直接从页缓存拿
Span* PageCache::NewSpan(size_t npage)
{
	std::unique_lock<std::mutex> lock(_mutex);
	 
	if (npage > NPAGES - 1)
	{
		//要向系统中拿内存
		void *ptr = SystemAlloc(npage);
		Span* sysspan = new Span;
		sysspan->_pageid = (PageID)ptr >> PAGE_SHIFT;
		sysspan->_npage = npage;
		sysspan->_objsize = npage << PAGE_SHIFT;
		//不将ptr插入到sysspan中，直接放入map中
		_id_span_map[sysspan->_pageid] = sysspan;
		return sysspan;
	}
	Span* span = _NewSpan(npage);
	span->_objsize = npage << PAGE_SHIFT;
	return span;
}

Span* PageCache::_NewSpan(size_t npage)
{
	//npage对应的自由链表中有span就返回去
	if (!_pfreelist[npage].Empty())
	{
		return _pfreelist[npage].PopFront();
	}
	//若没有，向比npage更大的自由链表中找 
	for (size_t i = npage + 1; i < NPAGES; i++)
	{
		if (!_pfreelist[i].Empty())
		{
			Span* fetchspan = new Span;
			Span* span = _pfreelist[i].Begin();

			fetchspan->_pageid = span->_pageid + span->_npage - npage;
			fetchspan->_npage = npage;
			span->_npage -= npage;

			_pfreelist[i - npage].PushFront(span);
			for (size_t i = 0; i < fetchspan->_npage; ++i)   //改变被分出去的页和span的映射
			{
				_id_span_map[fetchspan->_pageid + i] = fetchspan;
			}
			return fetchspan;
		}
	}

	//npage对应的自由链表往后的自由链表都没有span
	//就需要向系统申请内存
	void* ptr = SystemAlloc(NPAGES - 1);

	Span* largespan = new Span;
	largespan->_pageid = (PageID)ptr >> PAGE_SHIFT;
	largespan->_npage = NPAGES - 1;
	_pfreelist[NPAGES - 1].PushFront(largespan);

	for (size_t i = 0; i < largespan->_npage; ++i)
	{
		_id_span_map[largespan->_pageid + i] = largespan;
	}

	return _NewSpan(npage);
}

//释放空闲span回到Pagecache，并合并相邻的span
void PageCache::ReleaseSpanToPageCache(Span* span)
{
	std::unique_lock<std::mutex> lock(_mutex);

	if (span->_npage >= NPAGES)
	{
		void *ptr = (void*)(span->_pageid << PAGE_SHIFT);
		_id_span_map.erase(span->_pageid);
		SystemFree(ptr);
		delete span;
		return;
	}

	//1、先找span对应页的前一页，若前一页为空闲，则合并
	auto previt = _id_span_map.find(span->_pageid - 1);
	while (previt != _id_span_map.end())
	{
		Span* prevspan = previt->second;
		if (prevspan->_usecount != 0)  //前一页不空闲，不合并
			break;
		if (prevspan->_npage + span->_npage > NPAGES - 1)  //如果合并出超过NPAGES页的span，则不合并，否则没办法管理
			break;

		_pfreelist[prevspan->_npage].Erase(prevspan);
		prevspan->_npage += span->_npage;
		delete span;
		span = prevspan;

		previt = _id_span_map.find(span->_pageid - 1);
	}
	//2、找span对应页的后一页，若后一页为空闲，则合并
	auto nextit = _id_span_map.find(span->_pageid + span->_npage);
	while (nextit != _id_span_map.end())
	{
		Span* nextspan = nextit->second;
		if (nextspan->_usecount != 0)  //前一页不空闲，不合并
			break;
		if (nextspan->_npage + span->_npage > NPAGES - 1)  //如果合并出超过NPAGES页的span，则不合并，否则没办法管理
			break;

		_pfreelist[nextspan->_npage].Erase(nextspan);
		span->_npage += nextspan->_npage;
		delete nextspan;

		nextit = _id_span_map.find(span->_pageid + span->_npage);
	}

	for (size_t i = 0; i < span->_npage; i++)
	{
		_id_span_map[span->_pageid + i] = span;
	}
	_pfreelist[span->_npage].PushFront(span);
}