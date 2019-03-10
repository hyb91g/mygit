#pragma once
#include "Common.h"

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}

	//中心缓存不够时，向页缓存中拿出一块新的span
	Span* NewSpan(size_t npage);
	Span* _NewSpan(size_t npage);

	//获取从对象到span的映射
	Span* MapObjectToSpan(void* obj);

	//释放空闲span回到Pagecache，并合并相邻的span
	void ReleaseSpanToPageCache(Span* span);

private:
	SpanList _pfreelist[NPAGES];

	//std::map<PageID, Span*> _id_span_map;
	std::unordered_map<PageID, Span*> _id_span_map;
	std::mutex _mutex;

	//单例模式
	PageCache() = default;
	PageCache(const PageCache&) = delete;
	PageCache operator=(const PageCache&) = delete;
	static PageCache _inst;
};