//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。


#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.empty())
			return true;
		stack<char> st;
		for (auto e : s)
		{
			if (st.empty())
			{
				if (e == '(' || e == '[' || e == '{')
				{
					st.push(e);
				}
				else
					return false;
			}
			else
			{
				if (e == '(' || e == '[' || e == '{')
				{
					st.push(e);
				}
				else
				{
					switch (e)
					{
					case ')':
						if (st.top() == '(')
							st.pop();
						else
							return false;
						break;
					case ']':
						if (st.top() == '[')
							st.pop();
						else
							return false;
						break;
					case '}':
						if (st.top() == '{')
							st.pop();
						else
							return false;
						break;
					}
				}
			}
		}
		if (st.empty())
		{
			return true;
		}
		else
			return false;
	}
};

int main()
{
	string s = "[])";
	Solution S;
	cout << S.isValid(s) << endl;
	return 0;
}