#include "Vector.h"

template<class T>
void Vector<T>::Resize(size_t n, const T& val)
{
	if (n < Size())
	{
		_finish = _start + n;
	}
	else
	{
		if (n > Capacity())
		{
			Reserve(n);
		}
			Iterator it = _finish;
			for (it; it < _start + n; it++)
			{
				*it = val;
			}
			_finish = _start + n;
	}
}

template<class T>
void Vector<T>::Reserve(size_t n)
{
	if (n > Capacity())
	{
		T* tmp = new T[n];
		size_t size = Size();
		//if(_start)  //浅拷贝  导致多次释放
		//	memcpy(tmp, _start, sizeof(T)*size);

		if (_start) { 
			for (size_t i = 0; i < size; ++i)    
				tmp[i] = _start[i]; 
		}
		delete[] _start;
		_start = tmp;
		_finish = _start + size;
		_endofstorage = _start + n;
	}
}

template<class T>
void Vector<T>::Pushback(const T& val)
{
	Insert(end(), val);
}

template<class T>
void Vector<T>::Popback()
{
	Erase(end());
}

template<class T>
typename Vector<T>::Iterator Vector<T>::Insert(Vector<T>::Iterator pos, const T& val)
{
	assert(pos <= _finish);
	if (_finish == _endofstorage)
	{
		size_t n = pos - _start;
		size_t size = Size();
		size_t newcapacity = Capacity() == 0 ? 2 : 2 * Capacity();
		Reserve(newcapacity);
		pos = _start + n;     //增容需要重置pos
	}
	if (Size() != 0)
	{
		Iterator over = _finish - 1;
		while (over >= pos)
		{
			*(over + 1) = *over;
			over--;
		}
	}
	*pos = val;
	_finish++;
	return pos;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::Erase(Vector<T>::Iterator pos)
{
	assert(Size() > 0 && pos <= _finish);
	if (Size() > 1)
	{
		Iterator start = pos + 1;
		while (start < _finish)
		{
			*(start - 1) = *start;
			start++;
		}
	}
	_finish--;
	return pos;
}


void Test1()
{
	Vector<int> v1;
	v1.Pushback(1);
	v1.Pushback(2);
	v1.Pushback(3);
	for (Vector<int>::Iterator it = v1.begin(); it < v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	Vector<int> v2(3);
	for (Vector<int>::Iterator it = v2.begin() ; it < v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	Vector<string> v3(3, "abc");
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Test2()
{
	//Vector<int> v(10, 3);
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//v.Resize(3);
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//v.Resize(5);
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//v.Resize(8, 2);
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//v.Resize(20);
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	Vector<string> v(10, "ABC");
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.Resize(3);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.Resize(5);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.Resize(8, "abc");
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.Resize(20);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void Test3()
{
	int arr[] = { 1,2,3,4,5 };
	Vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

	Vector<int>::Iterator pos = find(v.begin(), v.end(), 2);
	v.Insert(pos, 6);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 2);
	v.Erase(pos);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}

int main()
{
	Test1();
	//Test2();
	//Test3();

	return 0;
}