#include "ThreadCache.h"
#include "CentralCache.h"

//从中心缓存中拿取内存，一次申请出批量的内存
void* ThreadCache::FetchFromCentralCache(size_t index, size_t bytes)
{
	FreeList& freelist = _tfreelist[index];
	//从中心缓存中拿多少个内存块，慢增长模式
	//若一次给少了，每次申请内存时都要向中心缓存中拿对象，这是要加锁的，代价很大
	//若一次给多了，又会造成内存浪费的问题
	size_t num = ClassSize::NumMoveSize(bytes) < freelist.MaxSize() ? ClassSize::NumMoveSize(bytes) : freelist.MaxSize();

	void *start, *end;  // 记录从中心缓存拿到的内存的起始块和结束块
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num, bytes);  //实际取到的内存块的个数，想取10块，不一定就能拿到10块
	if (fetchnum > 1)   // 取到多块:将第一块返回，将第一块后面的插入到线程缓存中
		freelist.PushRange(OBJ_NEXT(start), end, fetchnum - 1);
	if (num == freelist.MaxSize()) 
	{
		freelist.SetMaxSize(num + 1);  // 体现了慢增长
	}
	
	return start;
}


//分配内存
void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAXBYTES);

	//对齐取整
	size = ClassSize::Roundup(size);          //字节对齐   例：14字节对齐为16字节
	size_t index = ClassSize::Index(size);    //按字节得出下标

	FreeList& freelist = _tfreelist[index];   //从线程缓存的下标为index的自由链表中拿内存
	if (freelist.Empty())                     //若自由链表为空，则从中心缓存中拿取内存
	{
		return FetchFromCentralCache(index, size);
	}
	else									  //若自由链表不为空，从链表头部拿出使用
	{
		return freelist.PopFront();
	}
}

//解除分配
void ThreadCache::Deallocate(void* ptr, size_t size)
{
	assert(size <= MAXBYTES);
	//先找到内存大小对应的下标，再头插进自由链表
	size_t index = ClassSize::Index(size);
	FreeList& freelist = _tfreelist[index];
	freelist.PushFront(ptr);

	//当自由链表的数量超过一次批量从中心缓存移动的数量时，就开始回收对象到中心缓存
	if (freelist.Size() >= freelist.MaxSize())
	{
		ListTooLong(&freelist, index);
	}
}

void ThreadCache::ListTooLong(FreeList* freelist, size_t index)
{
	void *start = freelist->Claer();
	CentralCache::GetInstance()->ReleaseListToSpans(start, index);
}