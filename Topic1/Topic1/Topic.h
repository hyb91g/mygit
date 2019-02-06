#ifndef __TOPIC_H__
#define __TOPIC_H__

#include"queue.h"
#include"Stack.h"


// ����ջʵ��һ������
typedef struct QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack, *pQueueByTwoStack;

void QueueByTwoStackInit(pQueueByTwoStack qts);
void QueueByTwoStackDestory(pQueueByTwoStack qts);

void QueueByTwoStackPush(pQueueByTwoStack qts, DataType x);
void QueueByTwoStackPop(pQueueByTwoStack qts);
DataType QueueByTwoStackFront(pQueueByTwoStack qts);

int QueueByTwoStackSize(pQueueByTwoStack qts);
int QueueByTwoStackEmpty(pQueueByTwoStack qts);

void TestQueueByTwoStack();


/////////////////////////////////////////////////////////


// ��������ʵ��һ��ջ
typedef struct StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* stq);
void StackByTwoQueueDestory(StackByTwoQueue* stq);
DataType StackByTwoQueueTop(StackByTwoQueue* stq);
int StackByTwoQueueEmpty(StackByTwoQueue* stq);
int StackByTwoQueueSize(StackByTwoQueue* stq);

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x);
void StackByTwoQueuePop(StackByTwoQueue* stq);

void TestStackByTwoQueue();


#endif // !__TOPIC_H__


