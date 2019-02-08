#ifndef __STACK_H__
#define __STACK_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DateType;
#define N 10

typedef struct Stack
{
	DateType* _a;
	int _top; //Õ»¶¥
	int _capacity; //ÈÝÁ¿
}Stack, *pStack;

void StackInit(pStack ps);
void StackDestory(pStack ps);

void StackPush(pStack ps, DateType x);
void StackPop(pStack ps);
DateType StackTop(pStack ps);
int StackEmpty(pStack ps);
int StackSize(pStack ps);

#endif // !__STACK_H__
