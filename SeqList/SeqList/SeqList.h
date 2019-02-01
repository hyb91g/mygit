#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<string.h>
#include<assert.h>

#define MAX 100
typedef int DateType;

typedef struct SeqList
{
	DateType date[MAX];//数据
	int sz;//记录数据个数
}SeqList, *pSeqList;

void InitSeqList(pSeqList pseq);
void PushBack(pSeqList pseq, DateType d);
void PopBack(pSeqList pseq);
void PushFront(pSeqList pseq, DateType d);
void PopFront(pSeqList pseq);
int Find(pSeqList pseq, DateType d);
void Insert(pSeqList pseq, int pos, DateType d);
void Erase(pSeqList pseq, int pos);
void Remove(pSeqList pseq, DateType d);
void RemoveAll(pSeqList pseq, DateType d);
void PrintSeqList(pSeqList pseq);

#endif //__SEQLIST_H__