#ifndef __LINKLIST_H__ 
#define __LINKLIST_H__ 

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, List, *pList;

void InitLinkList(pList* pplist);
pNode BuyNode(DataType d);
void DestroyLinkList(pList* pplist);
void PushBack(pList* pplist, DataType d);
void PopBack(pList* pplist);
void PushFront(pList* pplist, DataType d);
void PopFront(pList* pplist);
pNode Find(pList plist, DataType d);

//在指定位置之前插入一个值 
void Insert(pList* pplist, pNode pos, DataType d);
//指定位置删除 
void Erase(pList* pplist, pNode pos);
void Remove(pList* pplist, DataType d);
void RemoveAll(pList* pplist, DataType d);
void EraseNotTailNode(pNode pos);
void PrintLinkList(pList plist);
int GetListLength(pList plist);
//链表面试题 

//逆序打印单项链表 
void PrintTailToHead(pList plist);
//删除一个无头单链表的非尾节点
void EraseNotTail(pNode pos);
//在无头单链表的一个节点前插入一个节点
void InsertNode(pNode pos, );


#endif //__LINKLIST_H__ 
