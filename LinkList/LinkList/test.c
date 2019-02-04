#include"LinkList.h"

void Test()
{
	//pList plist = NULL;
	//InitLinkList(&plist);
	//PushBack(&plist, 1);
	//PushBack(&plist, 2);
	//PushBack(&plist, 3);
	//PushBack(&plist, 4);
	//PrintLinkList(plist);
	//
	//PopBack(&plist);
	//PrintLinkList(plist);
	//PopBack(&plist);
	//PrintLinkList(plist);
	//PopBack(&plist);
	//PrintLinkList(plist);
	//PopBack(&plist);
	//PrintLinkList(plist);

	//pList plist = NULL;
	//InitLinkList(&plist);
	//PushFront(&plist, 1);
	//PushFront(&plist, 2);
	//PushFront(&plist, 3);
	//PushFront(&plist, 4);
	//PrintLinkList(plist);
	//pNode pos = NULL;
	//if ((pos = Find(plist, 1)) != NULL);
	//printf("%d\n",Find(plist, 1)->data);
	//Insert(&plist, pos, 5);
	//PrintLinkList(plist);

	//pList plist = NULL;
	//InitLinkList(&plist);
	//PushFront(&plist, 1);
	//PushFront(&plist, 2);
	//PushFront(&plist, 3);
	//PushFront(&plist, 4);
	//PrintLinkList(plist);
	//pNode pos = NULL;
	//if ((pos = Find(plist, 1)) != NULL);
	//printf("%d\n", Find(plist, 1)->data);
	//Erase(&plist, pos);
	//PrintLinkList(plist);

	//pList plist = NULL;
	//InitLinkList(&plist);
	//PushFront(&plist, 1);
	//PushFront(&plist, 2);
	//PushFront(&plist, 3);
	//PushFront(&plist, 4);
	//PrintLinkList(plist);
	//Remove(&plist, 4);
	//PrintLinkList(plist);

	//pList plist = NULL;
	//InitLinkList(&plist);
	//PushFront(&plist, 1);
	//PushFront(&plist, 2);
	//PushFront(&plist, 3);
	//PushFront(&plist, 4);
	//PushFront(&plist, 1);
	//PushFront(&plist, 4);
	//PushFront(&plist, 3);
	//PushFront(&plist, 4);
	//PrintLinkList(plist);
	//RemoveAll(&plist, 4);
	//PrintLinkList(plist);

	//pList plist = NULL;
	//InitLinkList(&plist);
	//PushFront(&plist, 1);
	//PushFront(&plist, 2);
	//PushFront(&plist, 3);
	//PushFront(&plist, 4);
	//PrintLinkList(plist);
	//pNode pos = NULL;
	//if ((pos = Find(plist, 2)) != NULL);
	//	printf("%d\n", Find(plist, 2)->data);
	//EraseNotTailNode(pos);
	//PrintLinkList(plist);

	//pList plist = NULL;
	//InitLinkList(&plist);
	//PushFront(&plist, 1);
	//PushFront(&plist, 2);
	//PushFront(&plist, 3);
	//PushFront(&plist, 4);
	//PrintLinkList(plist);
	//printf("%d\n", GetListLength(plist));

	//PopFront(&plist);
	//PrintLinkList(plist);
	//PopFront(&plist);
	//PrintLinkList(plist);
	//PopFront(&plist);
	//PrintLinkList(plist);
	//PopFront(&plist);
	//PrintLinkList(plist);

	//面试题
	
	//逆序打印单项链表
	pList plist = NULL;
	InitLinkList(&plist);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	PrintTailToHead(plist);

}
int main()
{
	Test();
	return 0;
}