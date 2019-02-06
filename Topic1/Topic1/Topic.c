#include"Topic.h"


//两个栈实现一个队列

void QueueByTwoStackInit(pQueueByTwoStack qts)
{
	assert(qts);
	StackInit(&(qts->s1));
	StackInit(&(qts->s2));
}

void QueueByTwoStackDestory(pQueueByTwoStack qts)
{
	assert(qts);
	StackDestory(&(qts->s1));
	StackDestory(&(qts->s2));
}

void QueueByTwoStackPush(pQueueByTwoStack qts, DataType x)
{
	assert(qts);
	StackPush(&(qts->s1), x);
}

void QueueByTwoStackPop(pQueueByTwoStack qts)
{
	assert(qts);
	if (StackEmpty(&qts->s2) == 0)
	{
		while (StackEmpty(&qts->s1))
		{
			StackPush(&qts->s2, StackTop(&qts->s1));
			StackPop(&qts->s1);
		}
	}
	StackPop(&qts->s2);
}

DataType QueueByTwoStackFront(pQueueByTwoStack qts)
{
	assert(qts);
	if (StackEmpty(&qts->s2) == 0)
	{
		while (StackEmpty(&qts->s1))
		{
			StackPush(&qts->s2, StackTop(&qts->s1));
			StackPop(&qts->s1);
		}
	}
	return StackTop(&qts->s2);
}

int QueueByTwoStackSize(pQueueByTwoStack qts)
{
	assert(qts);
	return StackSize(&qts->s1) + StackSize(&qts->s2);
}

int QueueByTwoStackEmpty(pQueueByTwoStack qts)
{
	return StackEmpty(&qts->s1) | StackEmpty(&qts->s2);
}

void TestQueueByTwoStack()
{
	QueueByTwoStack q;
	QueueByTwoStackInit(&q);
	QueueByTwoStackPush(&q, 1);
	QueueByTwoStackPush(&q, 2);
	QueueByTwoStackPush(&q, 3);
	QueueByTwoStackPush(&q, 4);

	QueueByTwoStackPop(&q);
	QueueByTwoStackPop(&q);

	QueueByTwoStackPush(&q, 5);
	QueueByTwoStackPush(&q, 6);

	while (QueueByTwoStackEmpty(&q))
	{
		printf("%d ", QueueByTwoStackFront(&q));
		QueueByTwoStackPop(&q);
	}
}


///////////////////////////////////////////////////////////////////

//两个队列实现一个栈

void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	assert(stq);
	QueueInit(&stq->q1);
	QueueInit(&stq->q2);
}

void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	assert(stq);
	QueueDestory(&stq->q1);
	QueueDestory(&stq->q2);
}

DataType StackByTwoQueueTop(StackByTwoQueue* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->q1) != 0)
		return stq->q1._back->_date;
	else
		return stq->q2._back->_date;
}

int StackByTwoQueueEmpty(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueEmpty(&stq->q1) | QueueEmpty(&stq->q2);
}

int StackByTwoQueueSize(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueSize(&stq->q1) + QueueSize(&stq->q2);
}

void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x)
{
	assert(stq);
	if (QueueEmpty(&stq->q1) != 0)
		QueuePush(&stq->q1, x);
	else
		QueuePush(&stq->q2, x);
}

void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	Queue* empty;
	Queue* enempty;
	assert(stq);
	empty = &stq->q1;
	enempty = &stq->q2;
	if (QueueEmpty(&stq->q1) != 0)
	{
		empty = &stq->q2;
		enempty = &stq->q1;
	}
	while (QueueSize(enempty) != 1)
	{
		QueuePush(empty, QueueFront(enempty));
		QueuePop(enempty);
	}
	QueuePop(enempty);
}

void TestStackByTwoQueue()
{
	StackByTwoQueue s;
	StackByTwoQueueInit(&s);
	StackByTwoQueuePush(&s, 1);
	StackByTwoQueuePush(&s, 2);
	StackByTwoQueuePush(&s, 3);
	StackByTwoQueuePush(&s, 4);
	while (StackByTwoQueueEmpty(&s))
	{
		printf("%d ", StackByTwoQueueTop(&s));
		StackByTwoQueuePop(&s);
	}
}

int main()
{
	//TestQueueByTwoStack();
	TestStackByTwoQueue();
	return 0;
}