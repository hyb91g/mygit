#include"List.h"

void Test()
{
	List L;
	pListNode ret;
	ListInit(&L);
	ListPushBack(&L, 1);
	ListPushBack(&L, 2);
	ListPushBack(&L, 3);
	ListPushFront(&L, 4);
	ListPushFront(&L, 5);
	ListPushFront(&L, 6);
	ListPrint(&L);
	ret = ListFind(&L, 5);
	printf("%d\n", ret->data);
	ret = ListFind(&L, 8);
	printf("%p\n", ret);

	ListErase(L.head->next);
	ListPrint(&L);

	ListPopFront(&L);
	ListPrint(&L);

	ListPopBack(&L);
	ListPrint(&L);
	printf("%d\n", ListSize(&L));
	ListDestory(&L);
}

int main()
{
	Test();
	return 0;
}