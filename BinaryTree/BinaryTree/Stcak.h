#ifndef __STACK_H__
#define __STACK_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"BinaryTree.h"


typedef BTNode* SDataType;
#define N 10

typedef struct Stack
{
	SDataType* _a;
	int _top; //Õ»¶¥
	int _capacity; //ÈÝÁ¿
}Stack, *pStack;

void StackInit(pStack ps);
void StackDestory(pStack ps);

void StackPush(pStack ps, SDataType x);
void StackPop(pStack ps);
SDataType StackTop(pStack ps);
int StackEmpty(pStack ps);
int StackSize(pStack ps);

#endif // !__STACK_H__
