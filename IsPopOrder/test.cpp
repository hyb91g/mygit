#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
			return false;
		int size = pushV.size();
		int push_step = 0;
		int pop_step = 0;
		while (pop_step != size)
		{
			while (st.empty() || popV[pop_step] != st.top())
			{
				if (push_step == size)
					return false;
				st.push(pushV[push_step++]);
			}
			st.pop();
			pop_step++;
		}
		return true;
	}

private:
	stack<int> st;
};

int main()
{
	vector<int> v1;
	vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(2);
	v2.push_back(1);
	v2.push_back(5);


	Solution s;
	cout << s.IsPopOrder(v1, v2) << endl;

	return 0;
}