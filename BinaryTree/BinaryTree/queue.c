#include"queue.h"

void QueueInit(pQueue pq)
{
	assert(pq);
	pq->_back = NULL;
	pq->_front = NULL;
}

void QueueDestory(pQueue pq)
{
	QueueNode* cur;
	QueueNode* tmp;
	assert(pq);
	cur = pq->_front;
	while (cur)
	{
		tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	pq->_front = pq->_back = NULL;
}

QueueNode* BuyQueueNode(DataType x)
{
	QueueNode*cur = (QueueNode*)malloc(sizeof(QueueNode));
	if (cur == NULL)
	{
		perror("use malloc");
	}
	cur->_date = x;
	cur->_next = NULL;
	return cur;
}

void QueuePush(pQueue pq, DataType x)
{
	QueueNode* cur;
	assert(pq);
	cur = BuyQueueNode(x);
	if (pq->_front == NULL)
	{
		pq->_back = cur;
		pq->_front = cur;
	}
	else
	{
		pq->_back->_next = cur;
		pq->_back = cur;
	}
}

void QueuePop(pQueue pq)
{
	QueueNode* cur;
	assert(pq);
	cur = pq->_front;
	pq->_front = cur->_next;
	free(cur);
	cur = NULL;
	if (pq->_front == NULL)
		pq->_back = NULL;
}

DataType QueueFront(pQueue pq)
{
	assert(pq);
	return pq->_front->_date;
}

//¿Õ   0
//·Ç¿Õ 1
int QueueEmpty(pQueue pq)
{
	assert(pq);
	return pq->_front == NULL ? 0 : 1;
}

int QueueSize(pQueue pq)
{
	QueueNode* cur;
	int count = 0;
	assert(pq);
	cur = pq->_front;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}