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

void TestFind()  //����ָ��Ԫ��
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
		printf("û�ҵ�\n");
	}
	else
	{
		printf("�ҵ��ˣ��±�Ϊ%d\n", pos);
	}
}

void TestInsert()//ָ��λ�ò��� 
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

void TestErase()//ɾ��ָ��λ��Ԫ��
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

void TestRemove()//ɾ��ָ��Ԫ��
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
	//TestFind(); //����ָ��Ԫ��
	//TestInsert();//ָ��λ�ò��� 
	//TestErase();//ɾ��ָ��λ��Ԫ��
	//TestRemove();//ɾ��ָ��Ԫ��
	TestRemoveAll();//ɾ�����е�ָ��Ԫ�� 
	return 0;
}