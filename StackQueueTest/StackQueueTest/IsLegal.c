#include"StackQueueTest.h"


int IsLegalStackOrder(int* in, int insize, int* out, int outsize)
{
	Stack st;
	int inindex = 0;
	int outindex = 0;
	assert(in && out && insize == outsize);
	StackInit(&st);
	while (inindex < insize)
	{
		StackPush(&st, in[inindex]);
		while (StackEmpty(&st) && (out[outindex] == StackTop(&st)))
		{
			StackPop(&st);
			outindex++;
		}
		inindex++;
	}
	if (StackEmpty(&st) == 0)
		return 1;
	else
		return 0;
}

void TestIsLegal()
{
	int in[] = { 1,2,3,4,5 };
	//int out[] = { 4,5,3,2,1 };
	int out[] = { 4,5,2,3,1 };
	if (IsLegalStackOrder(in, 5, out, 5) == 1)
		printf("合法\n");
	else
		printf("不合法\n");
}