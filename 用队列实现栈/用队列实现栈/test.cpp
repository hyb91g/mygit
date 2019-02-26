#include <iostream>
#include <queue>
#include <assert.h>
using namespace std;
class MyStack {
public:
	MyStack() {}

	void push(int x) {
		q1.size() > q2.size() ? q1.push(x) : q2.push(x);
	}

	int pop() {
		assert(!q1.empty() || !q2.empty());
		int ret;
		queue<int> *min = &q2;
		queue<int> *max = &q1;
		if (q1.empty())
		{
			min = &q1;
			max = &q2;
		}


		if (max->size() == 1)
		{
			ret = max->front();
			max->pop();
			return ret;
		}
		else
		{
			int tmp;
			while (max->size() > 1)
			{
				tmp = max->front();
				max->pop();
				min->push(tmp);
			}
			ret = max->front();
			max->pop();
			return ret;
		}
	}

	int top() {
		assert(!q1.empty() || !q2.empty());
		return q1.size() > q2.size() ? q1.back() : q2.back();
	}

	bool empty() {
		return q1.empty() && q2.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};


int main()
{
	MyStack *obj = new MyStack();
	obj->push(1);
	obj->push(2);
	cout << obj->pop() << endl;
	cout << obj->top() << endl;
	cout << obj->empty() << endl;
	return 0;
}
