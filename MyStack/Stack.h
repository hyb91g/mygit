#pragma once

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

template<class T, class Container = deque<T>>
class Stack
{
public:
	void Push(const T& val)
	{
		c.push_back(val);
	}
	void Pop()
	{
		c.pop_back();
	}
	T Top()
	{
		return c.back();
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
	Container c;
};
