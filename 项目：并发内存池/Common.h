#pragma once
#include <iostream>
#include <assert.h>
#include <thread>
#include <mutex>
#include <unordered_map>
#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

const size_t NLISTS = 240;  //管理对象有240个自由链表
const size_t MAXBYTES = 64 * 1024;  //自由链表的最大字节数
const size_t NPAGES = 129;  //页缓存中自由链表的最大页数
const size_t PAGE_SHIFT = 12;  //一页：4k  4*1024: 1<<12

static inline void* SystemAlloc(size_t npage)  //向系统申请npage个页
{
	void* ptr;
#ifdef  _WIN32
	ptr = VirtualAlloc(NULL, npage << PAGE_SHIFT, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}
#else
	//brk mmap
#endif //  _WIN32

	return ptr;
}

static inline void SystemFree(void* ptr)  
{
#ifdef  _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
	if (ptr == nullptr)
	{
		throw std::bad_alloc();
	}
#else
	//brk mumap
#endif //  _WIN32
}

static inline void*& OBJ_NEXT(void* obj)
{
	return *(void**)obj;
}

typedef size_t PageID;
struct Span
{
	PageID _pageid = 0;			// 页号
	size_t _npage = 0;		// 页的数量
	
	Span* _next = nullptr;
	Span* _prev = nullptr;

	void* _list = nullptr;		// 自由链表
	size_t _objsize = 0;        // 对象大小
	size_t _usecount = 0;		// 使用计数
};
//SpanList管理的是一个个带头双向链表
class SpanList
{
public:
	SpanList()
	{
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}

	Span* Begin()
	{
		return _head->_next;
	}
	Span* End()
	{
		return _head;
	}

	void Insert(Span* cur, Span* newspan)
	{
		assert(cur);
		Span* prev = cur->_prev;
		//prev newspan cur
		prev->_next = newspan;
		newspan->_prev = prev;
		newspan->_next = cur;
		cur->_prev = newspan;
	}

	void Erase(Span* cur)
	{
		assert(cur != nullptr && cur != _head);
		Span* prev = cur->_prev;
		Span* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;
	}
	void PushFront(Span* newspan)
	{
		Insert(Begin(), newspan);
	}
	Span* PopFront()
	{
		Span* front = Begin();
		Erase(front);
		return front;
	}
	void PushBack(Span* span)
	{
		Insert(End(), span);
	}
	Span* PopBack()
	{
		Span* tail = _head->_prev;
		Erase(tail);
		return tail;
	}
	bool Empty()
	{
		return  _head->_next == _head;
	}
public:
	std::mutex _mutex;
private:
	Span* _head = nullptr;   
};

class FreeList
{
public:
	bool Empty()
	{
		return _list == nullptr;
	}
	void* PopFront()
	{
		void* obj = _list;
		_list = OBJ_NEXT(_list);

		_size--;
		return obj;
	}
	void PushFront(void* obj)
	{
		OBJ_NEXT(obj) = _list;
		_list = obj;

		_size++;
	}
	void PushRange(void* start, void* end, size_t num)
	{
		OBJ_NEXT(end) = _list;
		_list = start;
		_size += num;
	}
	void* Claer()
	{
		_size = 0;
		void* ret = _list;
		_list = nullptr;
		return ret;
	}
	size_t Size()
	{
		return _size;
	}
	size_t MaxSize()
	{
		return _maxsize;
	}
	void SetMaxSize(size_t maxsize)
	{
		_maxsize = maxsize;
	}
private:
	void* _list = nullptr;  //自由链表的头指针

	size_t _size = 0;
	size_t _maxsize = 1;  //控制线程缓存从中心缓存中获取对象的最大个数（慢增长）
};

//管理对齐映射
class ClassSize
{
	// 控制在12%左右的内碎片浪费
	// [1,128]				8byte对齐	 freelist[0,16)
	// [129,1024]			16byte对齐   freelist[16,72)
	// [1025,8*1024]		128byte对齐  freelist[72,128)
	// [8*1024+1,64*1024]	512byte对齐  freelist[128,240)

public:
	static inline size_t _Roundup(size_t bytes, size_t align)  //align：对齐数
	{
		return (bytes + align - 1) & ~(align - 1);
	}
	static inline size_t _Index(size_t bytes, size_t align_shift)
	{
		return ((bytes + ((1 << align_shift) - 1)) >> align_shift) - 1;
		//例：传进来（16，3）  8字节对齐
		//(16 + ((1 << 3) - 1) >> 3 - 1
		//(16 +     8     - 1) /  8 - 1
		//得出下标为 1
	}

	//字节对齐 例：14字节对齐为16字节
	static inline size_t Roundup(size_t bytes)
	{
		assert(bytes <= MAXBYTES);
		if (bytes <= 128) {
			return _Roundup(bytes, 8);
		}
		else if (bytes <= 1024) {
			return _Roundup(bytes, 16);
		}
		else if (bytes <= 8192) {
			return _Roundup(bytes, 128);
		}
		else if (bytes <= 65536) {
			return _Roundup(bytes, 512);
		}
		else
			return -1;
	}

	//计算对齐下标
	static inline size_t Index(size_t bytes)
	{
		assert(bytes <= MAXBYTES);

		//每个区间有多少个自由链表
		static int freelist_array[] = { 16, 56, 56, 112 };

		if (bytes <= 128)
		{
			return _Index(bytes, 3);    //128内按8字节对齐  十进制8->二进制1000：1<<3位（三个0）
		}
		else if (bytes <= 1024) {
			return _Index(bytes, 4) + freelist_array[0];    //1024内按16字节对齐  十进制16->二进制10000：1<<4位（四个0）
		}
		else if (bytes <= 8192) {
			return _Index(bytes, 7) + freelist_array[0] + freelist_array[1];    //8192内按128字节对齐
		}
		else if (bytes <= 65536) {      
			return _Index(bytes, 9) + freelist_array[0] + freelist_array[1] + freelist_array[2];    //65536内按512字节对齐
		}
		else
			return -1;
	}

	static inline size_t NumMoveSize(size_t bytes)
	{
		if (bytes == 0)
			return 0;
		//大字节给少块，小字节给多块
		int num = (int)(MAXBYTES / bytes);
		if (num < 2)
			num = 2;
		if (num > 512)
			num = 512;
		return num;
	}

	//计算一次获取几个页
	static inline size_t NumMovePage(size_t bytes)
	{
		size_t num = NumMoveSize(bytes);
		size_t npage = (num*bytes) >> 12;
		if (npage == 0)
		{
			npage = 1;
		}
		return npage;
	}
};