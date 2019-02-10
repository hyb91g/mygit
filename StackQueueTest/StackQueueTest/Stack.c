#include"StackQueueTest.h"

void StackInit(pStack ps)
{
	assert(ps);
	ps->_a = (DataType*)malloc(sizeof(DataType)*N);
	ps->_top = 0;
	ps->_capacity = N;
}

void StackDestory(pStack ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
	free(ps->_a);
	ps = NULL;
}

void StackPush(pStack ps, DataType x)
{
	DataType* cur;
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		cur = (DataType*)realloc(ps->_a, sizeof(DataType) * 2 * ps->_capacity);
		if (cur != NULL)
		{
			ps->_a = cur;
		}
		ps->_capacity = 2 * ps->_capacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(pStack ps)
{
	assert(ps);
	assert(ps->_top > 0);

	ps->_top--;
}

DataType StackTop(pStack ps)
{
	assert(ps);
	assert(ps->_top > 0);
	return ps->_a[ps->_top - 1];
}

//¿Õ   0
//·Ç¿Õ 1
int StackEmpty(pStack ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(pStack ps)
{
	assert(ps);
	return ps->_top;
}