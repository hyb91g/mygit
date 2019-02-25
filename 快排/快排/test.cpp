#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	//void sort(vector<int>& v, int begin, int end)
	//{
	//	if (begin >= end)
	//	{
	//		return;
	//	}

	//	int i = begin;
	//	int j = end;
	//	int flag = v[j];//标志位，以flag为界限，大于flag置于右边，小于flag的置于左边
	//	while (i < j)
	//	{
	//		while ((v[i] <= flag) && (i < j))
	//		{
	//			i++;
	//		}
	//		v[j] = v[i];
	//		while ((v[j] >= flag) && (i < j))
	//		{
	//			j--;
	//		}
	//		v[i] = v[j];
	//	}
	//	v[i] = flag;

	//	sort(v, begin, i - 1);
	//	sort(v, i + 1, end);
	//}


	void sort(vector<int>& v)
	{
		struct SE
		{
			int start;
			int end;
		};

		SE se;
		se.start = 0;
		se.end = v.size() - 1;
		stack<SE> St;
		St.push(se);

		while (!St.empty())
		{
			/* 每次弹出栈顶元素 */
			SE cur = St.top();
			St.pop();
			if (cur.start >= cur.end)
			{
				/* 仅有一个元素时，不必比较 */
				continue;
			}
			int i = cur.start;
			int j = cur.end;
			int flag = v[j];
			while (i < j)
			{
				while ((v[i] <= flag) && ((i < j)))
				{
					i++;
				}
				v[j] = v[i];
				while ((v[j] >= flag) && (i < j))
				{
					j--;
				}
				v[i] = v[j];
			}
			v[i] = flag;

			int tmp = cur.start;
			/* flag右侧进栈 */
			cur.start = j + 1;
			St.push(cur);

			/* flag左侧进栈，先出 */
			SE next;
			next.end = j - 1;
			next.start = tmp;
			St.push(next);
		}
	}
};

int main()
{
	vector<int> v;
	v.push_back(15);
	v.push_back(4);
	v.push_back(1);
	v.push_back(8);
	v.push_back(3);
	v.push_back(2);
	Solution s;
	//s.sort(v, 0, v.size() - 1);
	s.sort(v);
	return 0;
}