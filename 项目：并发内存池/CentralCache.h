#pragma once
#include "Common.h"

class CentralCache
{
public:
	static CentralCache* GetInstance()
	{
		return &_inst;
	}

	//找到可用的span
	Span* GetOneSpan(SpanList* spanlist, size_t bytes);

	//从中心缓存拿内存给线程缓存
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t bytes);

	//将一定数量的对象释放到span跨度
	void ReleaseListToSpans(void* start, size_t index);

private:
	SpanList _spfreelist[NLISTS];  // 中心缓存自由链表

	//单例模式：为了保证全局只有唯一的central cache，这个类被设计成了单例模式
	CentralCache() = default;
	CentralCache(const CentralCache&) = delete;
	CentralCache& operator=(const CentralCache&) = delete;
	static CentralCache _inst;//中心缓存单例模式对象
};