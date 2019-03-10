#include "ThreadCache.h"
#include "CentralCache.h"

//�����Ļ�������ȡ�ڴ棬һ��������������ڴ�
void* ThreadCache::FetchFromCentralCache(size_t index, size_t bytes)
{
	FreeList& freelist = _tfreelist[index];
	//�����Ļ������ö��ٸ��ڴ�飬������ģʽ
	//��һ�θ����ˣ�ÿ�������ڴ�ʱ��Ҫ�����Ļ������ö�������Ҫ�����ģ����ۺܴ�
	//��һ�θ����ˣ��ֻ�����ڴ��˷ѵ�����
	size_t num = ClassSize::NumMoveSize(bytes) < freelist.MaxSize() ? ClassSize::NumMoveSize(bytes) : freelist.MaxSize();

	void *start, *end;  // ��¼�����Ļ����õ����ڴ����ʼ��ͽ�����
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num, bytes);  //ʵ��ȡ�����ڴ��ĸ�������ȡ10�飬��һ�������õ�10��
	if (fetchnum > 1)   // ȡ�����:����һ�鷵�أ�����һ�����Ĳ��뵽�̻߳�����
		freelist.PushRange(OBJ_NEXT(start), end, fetchnum - 1);
	if (num == freelist.MaxSize()) 
	{
		freelist.SetMaxSize(num + 1);  // ������������
	}
	
	return start;
}


//�����ڴ�
void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAXBYTES);

	//����ȡ��
	size = ClassSize::Roundup(size);          //�ֽڶ���   ����14�ֽڶ���Ϊ16�ֽ�
	size_t index = ClassSize::Index(size);    //���ֽڵó��±�

	FreeList& freelist = _tfreelist[index];   //���̻߳�����±�Ϊindex���������������ڴ�
	if (freelist.Empty())                     //����������Ϊ�գ�������Ļ�������ȡ�ڴ�
	{
		return FetchFromCentralCache(index, size);
	}
	else									  //����������Ϊ�գ�������ͷ���ó�ʹ��
	{
		return freelist.PopFront();
	}
}

//�������
void ThreadCache::Deallocate(void* ptr, size_t size)
{
	assert(size <= MAXBYTES);
	//���ҵ��ڴ��С��Ӧ���±꣬��ͷ�����������
	size_t index = ClassSize::Index(size);
	FreeList& freelist = _tfreelist[index];
	freelist.PushFront(ptr);

	//�������������������һ�����������Ļ����ƶ�������ʱ���Ϳ�ʼ���ն������Ļ���
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