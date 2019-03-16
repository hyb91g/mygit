#pragma once

#include <iostream>
#include <deque>

using namespace std;

template<class T, class Container = deque<T>>
class Queue
{
public:
	void Push(const T& val)
	{
		c.push_back(val);
	}
	void Pop()
	{
		c.pop_front();
	}
	T& Front()
	{
		return c.front();
	}
	T& Back()
	{
		return c.back();
	}
	const T& Front() const
	{
		return c.front();
	}
	const T& Back() const
	{
		return c.back();
	}
	size_t Size()const 
	{
		return c.size();
	}
	bool Empty()const 
	{ 
		return c.empty();
	}
private:
	Container c;
};