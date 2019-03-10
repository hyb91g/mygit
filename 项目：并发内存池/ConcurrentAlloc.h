#pragma once

#include "Common.h"
#include "ThreadCache.h"
#include "PageCache.h"

//多线程调用这个函数，并发的申请内存
static void* ConcurrentAlloc(size_t size)
{
	if (size > MAXBYTES)   //申请的内存大于64k，向页缓存申请内存;
	{
		//大于64k后，按一页(4k)对齐
		size_t roundsize = ClassSize::_Roundup(size, 1 << PAGE_SHIFT);
		size_t  npage = roundsize >> PAGE_SHIFT;

		Span* span = PageCache::GetInstance()->NewSpan(npage);
		void *ptr = (void*)(span->_pageid << PAGE_SHIFT);
		return ptr;
	}
	else
	{
		//通过tls,获取线程自己的threadcache
		if (tls_threadcache == nullptr)
		{
			tls_threadcache = new ThreadCache;
		}
		return tls_threadcache->Allocate(size);
	}
};

static void ConcurrentFree(void* ptr)
{
	Span* span = PageCache::GetInstance()->MapObjectToSpan(ptr);
	size_t size = span->_objsize;
	if (size > MAXBYTES)
	{
		PageCache::GetInstance()->ReleaseSpanToPageCache(span);
	}
	else
	{
		tls_threadcache->Deallocate(ptr, size);
	}
}