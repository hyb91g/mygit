#include"Stcak.h"

void StackInit(pStack ps)
{
	assert(ps);
	ps->_a = (SDataType*)malloc(sizeof(SDataType)*N);
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

void StackPush(pStack ps, SDataType x)
{
	SDataType* cur;
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		cur = (SDataType*)realloc(ps->_a, sizeof(SDataType) * 2 * ps->_capacity);
		if (cur == NULL)
		{
			return;
		}
		ps->_a = cur;
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

SDataType StackTop(pStack ps)
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