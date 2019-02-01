#include"SeqList.h"

void InitSeqList(pSeqList pseq)
{
	assert(pseq);
	pseq->sz = 0;
	memset(pseq->date, 0, sizeof(pseq->date));
}

void PushBack(pSeqList pseq, DateType d)
{
	assert(pseq);
	if (pseq->sz == MAX)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}
	pseq->date[pseq->sz] = d;
	pseq->sz++;
}
void PopBack(pSeqList pseq)
{
	assert(pseq);
	if (pseq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	pseq->sz--;
}

void PrintSeqList(pSeqList pseq)
{
	int i = 0;
	assert(pseq);
	if (pseq->sz == 0)
	{
		printf("顺序表为空\n");
		return;
	}
	for (i = 0; i < pseq->sz; i++)
	{
		printf("%d ", pseq->date[i]);
	}
	printf("\n");
}

void PushFront(pSeqList pseq, DateType d)
{
	int i = 0;
	assert(pseq);
	if (pseq->sz == MAX)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}
	else
	{
		for (i = pseq->sz; i > 0; i--)
		{
			pseq->date[i] = pseq->date[i - 1];
		}
		pseq->date[0] = d;
		pseq->sz++;
	}
}

void PopFront(pSeqList pseq)
{
	int i = 0;
	assert(pseq);
	if (pseq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	else
	{
		for (i = 0; i < pseq->sz - 1; i++)
		{
			pseq->date[i] = pseq->date[i + 1];
		}
		pseq->sz--;
	}
}

int Find(pSeqList pseq, DateType d)
{
	int i = 0;
	assert(pseq);
	for (i = 0; i < pseq->sz; i++)
	{
		if (pseq->date[i] == d)
			return i;
	}
	return -1;
}

void Insert(pSeqList pseq, int pos, DateType d)
{
	int i = 0;
	assert(pseq);
	assert(pos >= 0 && pos <= pseq->sz);
	if (pseq->sz == MAX)
	{
		printf("顺序表已满，无法插入\n");
		return;
	}
	for (i = pseq->sz - 1; i >= pos; i--)
	{
		pseq->date[i + 1] = pseq->date[i];
	}
	pseq->date[pos] = d;
	pseq->sz++;
}

void Erase(pSeqList pseq, int pos)
{
	int i = 0;
	assert(pseq);
	assert(pos >= 0 && pos <= pseq->sz);
	if (pseq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (i = pos; i < pseq->sz - 1; i++)
	{
		pseq->date[i] = pseq->date[i + 1];
	}
	pseq->sz--;
}

void Remove(pSeqList pseq, DateType d)
{
	int i = 0;
	int j = 0;
	assert(pseq);
	if (pseq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (i = 0; i < pseq->sz; i++)
	{
		if (pseq->date[i] == d)
		{
			for (j = i; j < pseq->sz - 1; j++)
			{
				pseq->date[j] = pseq->date[j + 1];
			}
			pseq->sz--;
			return;
		}
	}
	printf("删除元素不存在\n");
}

void RemoveAll(pSeqList pseq, DateType d)
{
	int i = 0;
	int j = 0;
	int count = 0;
	DateType* tmp = NULL;
	assert(pseq);
#if 0
	if (pseq->sz == 0)
	{
		printf("顺序表为空，无法删除\n");
		return;
	}
	for (i = 0; i < pseq->sz; i++)
	{
		if (pseq->date[i] == d)
		{
			for (j = i; j < pseq->sz - 1; j++)
			{
				pseq->date[j] = pseq->date[j + 1];
			}
			pseq->sz--;
			i--;
		}
	}
#endif

#if 0
	tmp = (DateType*)malloc(sizeof(DateType)*pseq->sz);
	for (i = 0; i < pseq->sz; i++)
	{
		if (pseq->date[i] != d)
		{
			tmp[count++] = pseq->date[i];
		}
	}
	memcpy(pseq->date, tmp, count * sizeof(DateType));
	pseq->sz = count;
	free(tmp);
	tmp = NULL;
#endif

#if 1
	for (i = 0; i < pseq->sz; i++)
	{
		if (pseq->date[i] != d)
		{
			pseq->date[count++] = pseq->date[i];
		}
	}
	pseq->sz = count;
#endif
}

