#include "PriorityQueue.h"

int main()
{
	PriorityQueue<int> pq;
	pq.Push(1);
	pq.Push(5);
	pq.Push(9);
	pq.Push(4);
	pq.Push(7);
	size_t size = pq.Size();
	for (size_t i = 0; i < size; i++)
	{
		cout << pq.Top() << " ";
		pq.Pop();
	}
	cout << endl;

	Less<int> less;
	cout << less(10, 20) << endl;
	cout << less.operator()(10, 20) << endl;

	return 0;
}