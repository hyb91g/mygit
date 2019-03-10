#pragma once
#include <iostream>
#include <assert.h>
#include <thread>
#include <mutex>
#include <unordered_map>
#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

const size_t NLISTS = 240;  //���������240����������
const size_t MAXBYTES = 64 * 1024;  //�������������ֽ���
const size_t NPAGES = 129;  //ҳ������������������ҳ��
const size_t PAGE_SHIFT = 12;  //һҳ��4k  4*1024: 1<<12

static inline void* SystemAlloc(size_t npage)  //��ϵͳ����npage��ҳ
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
	PageID _pageid = 0;			// ҳ��
	size_t _npage = 0;		// ҳ������
	
	Span* _next = nullptr;
	Span* _prev = nullptr;

	void* _list = nullptr;		// ��������
	size_t _objsize = 0;        // �����С
	size_t _usecount = 0;		// ʹ�ü���
};
//SpanList�������һ������ͷ˫������
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
	void* _list = nullptr;  //���������ͷָ��

	size_t _size = 0;
	size_t _maxsize = 1;  //�����̻߳�������Ļ����л�ȡ���������������������
};

//�������ӳ��
class ClassSize
{
	// ������12%���ҵ�����Ƭ�˷�
	// [1,128]				8byte����	 freelist[0,16)
	// [129,1024]			16byte����   freelist[16,72)
	// [1025,8*1024]		128byte����  freelist[72,128)
	// [8*1024+1,64*1024]	512byte����  freelist[128,240)

public:
	static inline size_t _Roundup(size_t bytes, size_t align)  //align��������
	{
		return (bytes + align - 1) & ~(align - 1);
	}
	static inline size_t _Index(size_t bytes, size_t align_shift)
	{
		return ((bytes + ((1 << align_shift) - 1)) >> align_shift) - 1;
		//������������16��3��  8�ֽڶ���
		//(16 + ((1 << 3) - 1) >> 3 - 1
		//(16 +     8     - 1) /  8 - 1
		//�ó��±�Ϊ 1
	}

	//�ֽڶ��� ����14�ֽڶ���Ϊ16�ֽ�
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

	//��������±�
	static inline size_t Index(size_t bytes)
	{
		assert(bytes <= MAXBYTES);

		//ÿ�������ж��ٸ���������
		static int freelist_array[] = { 16, 56, 56, 112 };

		if (bytes <= 128)
		{
			return _Index(bytes, 3);    //128�ڰ�8�ֽڶ���  ʮ����8->������1000��1<<3λ������0��
		}
		else if (bytes <= 1024) {
			return _Index(bytes, 4) + freelist_array[0];    //1024�ڰ�16�ֽڶ���  ʮ����16->������10000��1<<4λ���ĸ�0��
		}
		else if (bytes <= 8192) {
			return _Index(bytes, 7) + freelist_array[0] + freelist_array[1];    //8192�ڰ�128�ֽڶ���
		}
		else if (bytes <= 65536) {      
			return _Index(bytes, 9) + freelist_array[0] + freelist_array[1] + freelist_array[2];    //65536�ڰ�512�ֽڶ���
		}
		else
			return -1;
	}

	static inline size_t NumMoveSize(size_t bytes)
	{
		if (bytes == 0)
			return 0;
		//���ֽڸ��ٿ飬С�ֽڸ����
		int num = (int)(MAXBYTES / bytes);
		if (num < 2)
			num = 2;
		if (num > 512)
			num = 512;
		return num;
	}

	//����һ�λ�ȡ����ҳ
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