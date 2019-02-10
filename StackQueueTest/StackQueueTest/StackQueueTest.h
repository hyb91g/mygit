#ifndef __STACKQUEUETEST_H__
#define	__STACKQUEUETEST_H__

// Õ»

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataType;
#define N 10

typedef struct Stack
{
	DataType* _a;
	int _top; //Õ»¶¥
	int _capacity; //ÈÝÁ¿
}Stack, *pStack;

void StackInit(pStack ps);
void StackDestory(pStack ps);

void StackPush(pStack ps, DataType x);
void StackPop(pStack ps);
DataType StackTop(pStack ps);
int StackEmpty(pStack ps);
int StackSize(pStack ps);

/////////////////////////////////////////////////

//MIN
typedef struct MinStack
{
	Stack st;
	Stack minst;
}MinStack, *pMinStack;

void MinStackInit(pMinStack pms);
void MinStackDestory(pMinStack pms);

void MinStackPush(pMinStack pms, DataType x);
void MinStackPop(pMinStack pms);
DataType MinStackMin(pMinStack pms);
void TestMinStack();

///////////////////////////////////////////////////////////////////


//IsLegal
int IsLegalStackOrder(int* in, int insize, int* out, int outsize);
void TestIsLegal();


///////////////////////////////////////////////////////////////////////

#define X 100
typedef struct ShareStack
{
	DataType A[X];
	int top1;
	int top2;
}ShareStack, *pShareStack;

void ShareStackInit(pShareStack pss);
//void ShareStackDestory(pShareStack pss);
int ShareStackEmpty(pShareStack pss, int which);
void ShareStackPush(pShareStack pss, DataType x, int which);
void ShareStackPop(pShareStack pss, int which);
DataType ShareStackTop(pShareStack pss, int which);
void TestShareStack();


#endif // !__STACKQUEUETEST_H__