#include"List.h"

void ListInit(pList lt)
{
	assert(lt);
	lt->head = (pListNode)malloc(sizeof(ListNode));
	lt->head->prev = lt->head;
	lt->head->next = lt->head;
}
void ListDestory(pList lt)
{
	pListNode cur, del;
	assert(lt);
	cur = lt->head->next;
	while (cur->next!= lt->head)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	free(lt->head);
	lt->head = NULL;
}

pListNode BuyListNode(DataType x)
{
	pListNode New = (pListNode)malloc(sizeof(ListNode));
	New->data = x;
	New->next = NULL;
	New->prev = NULL;
	return New;
}

void ListPushBack(pList lt, DataType x)
{
	assert(lt);
	ListInsert(lt->head, x);
}

void ListPushFront(pList lt, DataType x)
{
	assert(lt);
	ListInsert(lt->head->next, x);
}

void ListPopBack(pList lt)
{
	assert(lt);
	ListErase(lt->head->prev);
}

void ListPopFront(pList lt)
{
	assert(lt);
	ListErase(lt->head->next);
}

pListNode ListFind(pList lt, DataType x)
{
	pListNode cur;
	assert(lt);
	cur = lt->head->next;
	while (cur != lt->head)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(pListNode pos, DataType x)
{
	pListNode NewNode;
	assert(pos);
	NewNode = BuyListNode(x);
	NewNode->data = x;
	NewNode->prev = pos->prev;
	pos->prev->next = NewNode;
	NewNode->next = pos;
	pos->prev = NewNode;
}

void ListErase(pListNode pos)
{
	pListNode cur;
	assert(pos);
	cur = pos;

	if (pos->next == pos)
	{
		printf("链表为空，无法删除！\n");
		return;
	}
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(cur);
	cur = NULL;
}

int ListSize(pList lt)
{
	int count = 0;
	pListNode cur;
	assert(lt);
	if (lt->head->next == lt->head)
		return 0;
	else
	{
		cur = lt->head->next;
		while (cur != lt->head)
		{
			count += 1;
			cur = cur->next;
		}
		return count;
	}

}

int ListEmpty(pList lt)
{
	assert(lt);
	if (lt->head->next == lt->head)
		return 0;
	else
		return 1;
}

void ListPrint(pList lt)
{
	pListNode cur;
	assert(lt);
	cur = lt->head->next;
	while (cur!= lt->head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
