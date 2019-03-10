#pragma once
#include "Common.h"

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}

	//���Ļ��治��ʱ����ҳ�������ó�һ���µ�span
	Span* NewSpan(size_t npage);
	Span* _NewSpan(size_t npage);

	//��ȡ�Ӷ���span��ӳ��
	Span* MapObjectToSpan(void* obj);

	//�ͷſ���span�ص�Pagecache�����ϲ����ڵ�span
	void ReleaseSpanToPageCache(Span* span);

private:
	SpanList _pfreelist[NPAGES];

	//std::map<PageID, Span*> _id_span_map;
	std::unordered_map<PageID, Span*> _id_span_map;
	std::mutex _mutex;

	//����ģʽ
	PageCache() = default;
	PageCache(const PageCache&) = delete;
	PageCache operator=(const PageCache&) = delete;
	static PageCache _inst;
};