#include"Heap.h"

void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustDown(HPDataType* a, int n, int root)
{
	int parent, child;
	assert(a);
	parent = root;
	child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void AdjustUp(HPDataType* a, int root)
{
	int child, parent;
	assert(a);
	child = root;
	parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] <= a[parent])
			break;
		else
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
	}
}

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	int i;
	assert(hp&&a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	
	//调堆
	for (i = (n - 2) / 2; i >= 0; i--)   //n是size，i是下标，所以要减2除2
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
	}

	hp->_a[hp->_size++] = x;
	AdjustUp(hp->_a, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}

void PrintHeap(Heap* hp)
{
	int i;
	assert(hp);
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

// 不要直接调Heap
void HeapSort(HPDataType* a, int n)
{
	int i = 0;
	assert(a);
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	while (n > 1)
	{
		Swap(&a[0], &a[n - 1]);
		n--;
		AdjustDown(a, n, 0);
	}
}

void TestHeap()
{
	Heap hp;
	HPDataType a[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	PrintHeap(&hp);
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	HeapPush(&hp, 100);
	PrintHeap(&hp);
	HeapPop(&hp);
	PrintHeap(&hp);

	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapTop(&hp));
}

int main()
{
	TestHeap();
	return 0;
}