#include"List.h"

int main()
{
	List<int> l(3,10);
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
	l.PopBack();
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
	l.PushFront(9);
	l.PushFront(8);
	l.PushFront(7);
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
	l.PopFront();
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << "size is : " << l.Size() << endl;
	l.Clear();
	List<int>::Iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}