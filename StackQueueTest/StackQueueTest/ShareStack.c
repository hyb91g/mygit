#include"StackQueueTest.h"

void ShareStackInit(pShareStack pss)
{
	assert(pss);
	pss->top1 = 0;
	pss->top2 = 1;
}

void ShareStackPush(pShareStack pss, DataType x, int which)
{
	assert(pss);
	assert(which == 1 || which == 2);
	if ((pss->top1 == X - 2) || (pss->top2 == X - 1))
	{
		printf("Õ»Âú\n");
		return;
	}
	if (which == 1)
	{
		pss->A[pss->top1] = x;
		pss->top1 += 2;
	}
	else
	{
		pss->A[pss->top2] = x;
		pss->top2 += 2;
	}
}

void ShareStackPop(pShareStack pss, int which)
{
	assert(pss);
	assert(which == 1 || which == 2);
	if (which == 1)
	{
		pss->top1 -= 2;
	}
	else
	{
		pss->top2 -= 2;
	}
}

int ShareStackEmpty(pShareStack pss, int which)
{
	assert(pss);
	assert(which == 1 || which == 2);
	if (((pss->top1 == 0) && which == 1) || ((pss->top2 == 1) && which == 2))
	{
		return 0;
	}
	else
		return 1;
}

DataType ShareStackTop(pShareStack pss, int which)
{
	assert(pss);
	assert(which == 1 || which == 2);
	if (which == 1)
	{
		return pss->A[pss->top1 - 2];
	}
	else
	{
		return pss->A[pss->top2 - 2];
	}
}

void TestShareStack()
{
	ShareStack ss;
	ShareStackInit(&ss);
	ShareStackPush(&ss, 1, 1);
	ShareStackPush(&ss, 2, 1);
	ShareStackPush(&ss, 3, 1);
	ShareStackPush(&ss, 1, 2);
	ShareStackPush(&ss, 2, 2);
	ShareStackPush(&ss, 3, 2);
	while (ShareStackEmpty(&ss, 1))
	{
		printf("%d ", ShareStackTop(&ss, 1));
		ShareStackPop(&ss, 1);
	}
	printf("\n");
	while (ShareStackEmpty(&ss, 2))
	{
		printf("%d ", ShareStackTop(&ss, 2));
		ShareStackPop(&ss, 2);
	}
}
