#include"SeqList.h"

void TestPushBack()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
}

void TestPopBack()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
}

void TestPushFront()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
}

void TestPopFront()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
}

void TestFind()  //查找指定元素
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	pos = Find(&seq, 2);
	if (pos == -1)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了，下标为%d\n", pos);
	}
}

void TestInsert()//指定位置插入 
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 2);
	if (pos != -1)
	{
		Insert(&seq, pos, 5);
		PrintSeqList(&seq);
	}
}

void TestErase()//删除指定位置元素
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 2);
	if (pos != -1)
	{
		Erase(&seq, pos);
		PrintSeqList(&seq);
	}
}

void TestRemove()//删除指定元素
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PushBack(&seq, 3);
	PushBack(&seq, 2);
	PrintSeqList(&seq);//12345632
	Remove(&seq, 3);
	PrintSeqList(&seq);//1245632
}

void TestRemoveAll()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PushBack(&seq, 3);
	PushBack(&seq, 2);
	PrintSeqList(&seq);//12345632
	RemoveAll(&seq, 3);
	PrintSeqList(&seq);//124562
}

int main()
{
	//TestPushBack();
	//TestPopBack();
	//TestPushFront();
	//TestPopFront();
	//TestFind(); //查找指定元素
	//TestInsert();//指定位置插入 
	//TestErase();//删除指定位置元素
	//TestRemove();//删除指定元素
	TestRemoveAll();//删除所有的指定元素 
	return 0;
}