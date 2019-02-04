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

//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(pList* pplist, pNode pos, DataType d);
//ָ��λ��ɾ�� 
void Erase(pList* pplist, pNode pos);
void Remove(pList* pplist, DataType d);
void RemoveAll(pList* pplist, DataType d);
void EraseNotTailNode(pNode pos);
void PrintLinkList(pList plist);
int GetListLength(pList plist);
//���������� 

//�����ӡ�������� 
void PrintTailToHead(pList plist);
//ɾ��һ����ͷ������ķ�β�ڵ�
void EraseNotTail(pNode pos);
//����ͷ�������һ���ڵ�ǰ����һ���ڵ�
void InsertNode(pNode pos, );


#endif //__LINKLIST_H__ 
