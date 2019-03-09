#pragma once
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

template<class T>
class Vector
{
public:
	typedef T* Iterator;
	typedef const T* constiterator;
	Iterator begin()
	{
		return _start;
	}
	Iterator end()
	{
		return _finish;
	}
	constiterator CBegin() const
	{
		return _start;
	}
	constiterator CEnd() const
	{
		return _finish;
	}
	size_t Capacity()
	{
		return _endofstorage - _start;
	}
	size_t Size()
	{
		return _finish - _start;
	}
	bool Empty(Vector<T> v)
	{
		return _start == nullptr ? true : false;
	}
	void Swap(Vector<T> v)
	{
		swap(_start, v._start); 
		swap(_finish, v._finish);  
		swap(_endOfStorage, v._endOfStorage);
	}

	Vector()
		: _start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
	{}

	Vector(int n, const T& val = T())  //T()  匿名对象
	{
		Reserve(n);
		while (n--)
		{
			Pushback(val);
		}
	}

	// 这里如果使用Iterator做迭代器，就会导致初始化的迭代器区间[first,last]只能是Vector的迭代器  
	// 这里重新声明迭代器，迭代器区间[first,last]可以是任意容器的迭代器区间。   
	template<class InputIterator>
	Vector(InputIterator first, InputIterator last)
	{
		Reserve(last - first);
		while (first != last)
		{
			Pushback(*first++);
		}
	}

	Vector(const Vector<T>& v)
	{
		Reserve(v.Capacity());

		Iterator it = Begin();
		constiterator cit = v.CBegin();
		while (*cit)
		{
			*it++ = *cit++;
		}

		_finish = _start + v.Size();
		_endofstorage = _start + v.Capacity();
	}

	Vector<T>& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	~Vector()
	{
		delete[] _start;
		_start = _finish = _endofstorage = nullptr;
	}

	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos]; 
	}

	void Resize(size_t n, const T& val = T());
	void Reserve(size_t n);
	void Pushback(const T& val);
	void Popback();
	Iterator Insert(Iterator pos, const T& val);
	Iterator Erase(Iterator pos);

private:
	Iterator _start;
	Iterator _finish;
	Iterator _endofstorage;
};