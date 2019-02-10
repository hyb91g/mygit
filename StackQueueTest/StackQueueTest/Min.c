#include"StackQueueTest.h"

void MinStackInit(pMinStack pms)
{
	assert(pms);
	StackInit(&pms->st);
	StackInit(&pms->minst);
}

void MinStackDestory(pMinStack pms)
{
	assert(pms);
	StackDestory(&pms->st);
	StackDestory(&pms->minst);
}

void MinStackPush(pMinStack pms, DataType x)
{
	assert(pms);
	StackPush(&pms->st, x);
	if (StackEmpty(&pms->minst) == 0 || x <= StackTop(&pms->minst))
	{
		StackPush(&pms->minst, x);
	}
}

void MinStackPop(pMinStack pms)
{
	assert(pms);
	if (StackTop(&pms->st) == StackTop(&pms->minst))
	{
		StackPop(&pms->minst);
	}
	StackPop(&pms->st);
}

DataType MinStackMin(pMinStack pms)
{
	assert(pms);
	return StackTop(&pms->minst);
}

void TestMinStack()
{
	MinStack ms;
	MinStackInit(&ms);
	MinStackPush(&ms, 4);
	MinStackPush(&ms, 5);
	MinStackPush(&ms, 3);
	MinStackPush(&ms, 3);
	MinStackPush(&ms, 2);
	MinStackPush(&ms, 3);

	while (StackEmpty(&ms.st) != 0)
	{
		printf("×îÐ¡Öµ£º%d\n", MinStackMin(&ms));
		MinStackPop(&ms);
	}
}