#include"LinkList.h"

void InitLinkList(pList* pplist)
{
	assert(pplist);
	*pplist = NULL;
}

pNode BuyNode(DataType d)
{
	pNode newnode = (pList)malloc(sizeof(Node));
	newnode->data = d;
	newnode->next = NULL;
	return newnode;
}

void DestroyLinkList(pList* pplist)
{
	assert(pplist);
	free(*pplist);
	*pplist = NULL;
}

void PushBack(pList* pplist, DataType d)
{
	pNode NewNode = NULL;
	pNode cur = NULL;
	assert(pplist);
	cur = *pplist;
	NewNode = BuyNode(d);
	if (*pplist == NULL)
	{
		*pplist = NewNode;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = NewNode;
	}
}

void PopBack(pList* pplist)
{
	pNode cur = NULL;
	assert(pplist);
	cur = *pplist;
	assert(*pplist);
	if (cur->next == NULL)
	{
		*pplist = NULL;
		free(cur);
		cur = NULL;
		return;
	}
	while (cur->next->next)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void PushFront(pList* pplist, DataType d)
{
	pNode NewNode = NULL;
	assert(pplist);
	NewNode = BuyNode(d);
	NewNode->next = *pplist;
	*pplist = NewNode;
}

void PopFront(pList* pplist)
{
	pNode cur = NULL;
	assert(pplist);
	assert(*pplist);
	cur = *pplist;
	*pplist = cur->next;
	free(cur);
	cur = NULL;
}

void PrintLinkList(pList plist)
{
	while (plist)
	{
		printf("%d-->", plist->data);
		plist = plist->next;
	}
	printf("Over\n");
}

pNode Find(pList plist, DataType d)
{
	pNode cur = NULL;
	assert(plist);
	cur = plist;
	while (cur->data != d)
	{
		cur = cur->next;
	}
	if(cur)
		return cur;
	return NULL;
}

void Insert(pList* pplist, pNode pos, DataType d)
{
	pNode cur = NULL;
	pNode NewNode = NULL;
	assert(pplist);
	assert(*pplist);
	assert(pos);
	NewNode = BuyNode(d);
	cur = *pplist;
	if (cur == pos)
	{
		NewNode->next = *pplist;
		*pplist = NewNode;
		return;
	}
	while (cur&&cur->next != pos)
		cur = cur->next;
	if (cur)
	{
		NewNode->next = pos;
		cur->next = NewNode;
	}
	return;
}

void Erase(pList* pplist, pNode pos)
{
	pNode cur = NULL;
	pNode del = NULL;
	assert(pplist);
	assert(*pplist);
	assert(pos);
	cur = *pplist;
	if (cur == pos)
	{
		del = *pplist;
		*pplist = del->next;
		free(del);
		del = NULL;
		return;
	}
	while (cur&&cur->next != pos)
	{
		cur = cur->next;
	}
	if (cur)
	{
		del = pos;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
}

void Remove(pList* pplist, DataType d)
{
	pList cur = NULL;
	pNode del = NULL;
	assert(pplist);
	assert(*pplist);
	cur = *pplist;
	if (cur->data == d)
	{
		del = *pplist;
		*pplist = del->next;
		free(del);
		del = NULL;
		return;
	}
	while (cur&&cur->next->data != d)
	{
		cur = cur->next;
	}
	if (cur)
	{
		del = cur->next;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
}

void RemoveAll(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode del = NULL;
	pNode prev = NULL;
	assert(pplist);
	assert(*pplist);
	cur = *pplist;
	prev = cur;
	while (cur)
	{
		if (cur->data == d)
		{
			if (cur == *pplist)
			{
				del = *pplist;
				*pplist = del->next;
				free(del);
				del = NULL;
				cur = *pplist;
			}
			else
			{
				del = cur;
				prev->next = cur->next;
				cur = cur->next;
				free(del);
				del = NULL;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void EraseNotTailNode(pNode pos)
{
	assert(pos);
	assert(pos->next);
	pNode del = pos->next;
	pos->data = del->data;
	pos->next = del->next;
	free(del);
	del = NULL;
}

int GetListLength(pList plist)
{
	int count = 0;
	pNode cur = plist;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

//面试题

void PrintTailToHead(pList plist)  //逆序打印单项链表
{
	pNode cur = NULL;
	pNode tail = NULL;
	assert(plist);
	cur = plist;
	while (cur != tail)
	{
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		printf("%d-->", cur->data);
		tail = cur;
		cur = plist;
	}
	printf("over\n");
}


//删除一个无头单链表的非尾节点
void EraseNotTail(pNode pos)
{

}

