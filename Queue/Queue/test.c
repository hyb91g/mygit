#include"queue.h"

void Test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("%d ", QueueSize(&q));
	printf("\n");
	while (QueueEmpty(&q) != 0)
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
}

int main()
{
	Test();
	return 0;
}