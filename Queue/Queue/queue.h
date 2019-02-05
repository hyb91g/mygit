#ifndef __QUEUE_H_
#define __QUEUE_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;

typedef struct QueueNode
{
	DataType _date;
	struct QueueNode* _next;
}QueueNode, *pQueueNode;

typedef struct Queue
{
	pQueueNode _front; // ∂”Õ∑
	pQueueNode _back;  // ∂”Œ≤
}Queue, *pQueue;

void QueueInit(pQueue pq);
void QueueDestory(pQueue pq);
QueueNode* BuyQueueNode(DataType x);
void QueuePush(pQueue pq, DataType x);
void QueuePop(pQueue pq);
DataType QueueFront(pQueue pq);
int QueueEmpty(pQueue pq);
int QueueSize(pQueue pq);


#endif // !__QUEUE_H_
