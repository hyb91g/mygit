#pragma once

#include <iostream>
#include <deque>
using namespace std;

template<class T>
class Greater
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x > y;
	}
};

template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T, class Container = deque<T>, class Compare = Greater<T>>
class PriorityQueue
{
public:
	void Push(const T& val)
	{
		c.push_back(val);
		AdjustUp(c.size() - 1);
	}
	void Pop()
	{
		swap(c[0], c[c.size() - 1]);
		c.pop_back();
		AdjustDown(0);
	}
	T Top()
	{
		return c[0];
	}
	size_t Size()
	{
		return c.size();
	}
	bool Empty()
	{
		return c.empty();
	}
private:
	void AdjustUp(size_t child)
	{
		size_t parent = (child - 1) / 2;
		while (child > 0)
		{
			if (c[child] > c[parent])
			{
				swap(c[child], c[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
	void AdjustDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		while (child < c.size())
		{
			if ((child + 1) < c.size() && c[child] < c[child + 1])
			{
				child++;
			}
			if (c[parent] < c[child])
			{
				swap(c[child], c[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

private:
	Container c;
};