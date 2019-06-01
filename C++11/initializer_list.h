#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>
#include <assert.h>
using namespace std;

template<class T>
class Vector
{
private:
	T * _array;
	size_t _capacity;
	size_t _size;
public:
	typedef T* Iterator;
	Iterator begin()
	{
		return _array;
	}
	Iterator end()
	{
		return &_array[_size];
	}
public:
	Vector(initializer_list<T> l)
		:_capacity(l.size())
		,_size(0)
	{
		_array = new T[_capacity];
		for (auto e : l)
		{
			_array[_size++] = e;
		}
	}

	Vector<T>& operator=(initializer_list<T> l)
	{
		size_t i = 0;
		for (auto e : l)
		{
			_array[i++] = e;
		}
		return *this;
	}
	T& operator[](size_t i)
	{
		assert(i < _size);
		return _array[i];
	}

};