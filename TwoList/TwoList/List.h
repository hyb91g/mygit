#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode
{
	DataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode, *pListNode;

typedef struct List
{
	pListNode head;
}List, *pList;

void ListInit(pList lt);
void ListDestory(pList lt);
void ListPushBack(pList lt, DataType x);
void ListPushFront(pList lt, DataType x);
void ListPopBack(pList lt);
void ListPopFront(pList lt);

pListNode BuyListNode(DataType x);
pListNode ListFind(pList lt, DataType x);
void ListInsert(pListNode pos, DataType x);
void ListErase(pListNode pos);
int ListSize(pList lt);
int ListEmpty(pList lt);
void ListPrint(pList lt);

