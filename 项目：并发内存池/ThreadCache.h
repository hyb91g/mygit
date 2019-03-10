#pragma once
#include "Common.h"

class ThreadCache
{
public:
	//分配多少内存
	void* Allocate(size_t size);
	//解除分配
	void Deallocate(void* ptr, size_t size);

	//从中心缓存中拿取内存
	void* FetchFromCentralCache(size_t index, size_t bytes);

	//当自由链表的数量超过一次批量从中心缓存移动的数量时，就开始回收对象到中心缓存
	void ListTooLong(FreeList* freelist, size_t index);
private:
	FreeList _tfreelist[NLISTS];  //线程缓存自由链表

	//怎么让每个线程获取到自己的线程缓存？
	//1.每个线程在获取自己的线程缓存时，需要加锁
	//size_t _tid;
	//ThreadCache* _next;
};
//2.thread local storage  线程本地存储（tls）保存每个线程本地的ThreadCache的指针，这样大部分情况下申请释放内存是不需要锁的。
//tls变量
static __declspec(thread) ThreadCache* tls_threadcache;
