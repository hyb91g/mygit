#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;
class MyQueue {
private:
	stack<int> st1;
	stack<int> st2;
public:
	/** Initialize your data structure here. */
	MyQueue() {}

	/** Push element x to the back of queue. */
	void push(int x) {
		st1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		assert(!st1.empty() || !st2.empty());
		int ret;
		if (st2.empty())
		{
			int tmp;
			while (st1.size() > 0)
			{
				tmp = st1.top();
				st1.pop();
				st2.push(tmp);
			}
			ret = st2.top();
			st2.pop();
		}
		else
		{
			ret = st2.top();
			st2.pop();
		}
		return ret;
	}

	/** Get the front element. */
	int peek() {
		assert(!st1.empty() || !st2.empty());
		if (st2.empty())
		{
			int tmp;
			while (st1.size() > 0)
			{
				tmp = st1.top();
				st1.pop();
				st2.push(tmp);
			}
		}
		return st2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return st1.empty() && st2.empty();
	}
};

int main()
{
	MyQueue *obj = new MyQueue();
	obj->push(1);
	obj->push(2);
	cout << obj->pop() << endl;
	cout << obj->peek() << endl;
	cout << obj->empty() << endl;
	return 0;
}