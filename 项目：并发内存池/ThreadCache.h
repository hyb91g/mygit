#pragma once
#include "Common.h"

class ThreadCache
{
public:
	//��������ڴ�
	void* Allocate(size_t size);
	//�������
	void Deallocate(void* ptr, size_t size);

	//�����Ļ�������ȡ�ڴ�
	void* FetchFromCentralCache(size_t index, size_t bytes);

	//�������������������һ�����������Ļ����ƶ�������ʱ���Ϳ�ʼ���ն������Ļ���
	void ListTooLong(FreeList* freelist, size_t index);
private:
	FreeList _tfreelist[NLISTS];  //�̻߳�����������

	//��ô��ÿ���̻߳�ȡ���Լ����̻߳��棿
	//1.ÿ���߳��ڻ�ȡ�Լ����̻߳���ʱ����Ҫ����
	//size_t _tid;
	//ThreadCache* _next;
};
//2.thread local storage  �̱߳��ش洢��tls������ÿ���̱߳��ص�ThreadCache��ָ�룬�����󲿷�����������ͷ��ڴ��ǲ���Ҫ���ġ�
//tls����
static __declspec(thread) ThreadCache* tls_threadcache;
