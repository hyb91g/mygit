#include"PageCache.h"

PageCache PageCache::_inst;

//��ȡ�Ӷ���span��ӳ�䣺���ݶ����ַ��ȡ
Span* PageCache::MapObjectToSpan(void* obj)
{
	PageID pageid = (PageID)obj >> PAGE_SHIFT;
	auto it = _id_span_map.find(pageid);
	assert(it != _id_span_map.end());

	return it->second;
}


//1�����Ļ��治��ʱ����ҳ�������ó�һ���µ�span
//2���̻߳�����Ҫ�Ķ������64kʱ��ֱ�Ӵ�ҳ������
Span* PageCache::NewSpan(size_t npage)
{
	std::unique_lock<std::mutex> lock(_mutex);
	 
	if (npage > NPAGES - 1)
	{
		//Ҫ��ϵͳ�����ڴ�
		void *ptr = SystemAlloc(npage);
		Span* sysspan = new Span;
		sysspan->_pageid = (PageID)ptr >> PAGE_SHIFT;
		sysspan->_npage = npage;
		sysspan->_objsize = npage << PAGE_SHIFT;
		//����ptr���뵽sysspan�У�ֱ�ӷ���map��
		_id_span_map[sysspan->_pageid] = sysspan;
		return sysspan;
	}
	Span* span = _NewSpan(npage);
	span->_objsize = npage << PAGE_SHIFT;
	return span;
}

Span* PageCache::_NewSpan(size_t npage)
{
	//npage��Ӧ��������������span�ͷ���ȥ
	if (!_pfreelist[npage].Empty())
	{
		return _pfreelist[npage].PopFront();
	}
	//��û�У����npage����������������� 
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
			for (size_t i = 0; i < fetchspan->_npage; ++i)   //�ı䱻�ֳ�ȥ��ҳ��span��ӳ��
			{
				_id_span_map[fetchspan->_pageid + i] = fetchspan;
			}
			return fetchspan;
		}
	}

	//npage��Ӧ�����������������������û��span
	//����Ҫ��ϵͳ�����ڴ�
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

//�ͷſ���span�ص�Pagecache�����ϲ����ڵ�span
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

	//1������span��Ӧҳ��ǰһҳ����ǰһҳΪ���У���ϲ�
	auto previt = _id_span_map.find(span->_pageid - 1);
	while (previt != _id_span_map.end())
	{
		Span* prevspan = previt->second;
		if (prevspan->_usecount != 0)  //ǰһҳ�����У����ϲ�
			break;
		if (prevspan->_npage + span->_npage > NPAGES - 1)  //����ϲ�������NPAGESҳ��span���򲻺ϲ�������û�취����
			break;

		_pfreelist[prevspan->_npage].Erase(prevspan);
		prevspan->_npage += span->_npage;
		delete span;
		span = prevspan;

		previt = _id_span_map.find(span->_pageid - 1);
	}
	//2����span��Ӧҳ�ĺ�һҳ������һҳΪ���У���ϲ�
	auto nextit = _id_span_map.find(span->_pageid + span->_npage);
	while (nextit != _id_span_map.end())
	{
		Span* nextspan = nextit->second;
		if (nextspan->_usecount != 0)  //ǰһҳ�����У����ϲ�
			break;
		if (nextspan->_npage + span->_npage > NPAGES - 1)  //����ϲ�������NPAGESҳ��span���򲻺ϲ�������û�취����
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