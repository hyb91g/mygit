#pragma once
#include "Common.h"

class CentralCache
{
public:
	static CentralCache* GetInstance()
	{
		return &_inst;
	}

	//�ҵ����õ�span
	Span* GetOneSpan(SpanList* spanlist, size_t bytes);

	//�����Ļ������ڴ���̻߳���
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t bytes);

	//��һ�������Ķ����ͷŵ�span���
	void ReleaseListToSpans(void* start, size_t index);

private:
	SpanList _spfreelist[NLISTS];  // ���Ļ�����������

	//����ģʽ��Ϊ�˱�֤ȫ��ֻ��Ψһ��central cache������౻��Ƴ��˵���ģʽ
	CentralCache() = default;
	CentralCache(const CentralCache&) = delete;
	CentralCache& operator=(const CentralCache&) = delete;
	static CentralCache _inst;//���Ļ��浥��ģʽ����
};