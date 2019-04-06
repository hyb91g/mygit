//逆波兰表达式求值
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//例：
//输入 : ["2", "1", "+", "3", "*"]
//	输出 : 9
//	解释 : ((2 + 1) * 3) = 9

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		for (int i = 0; i < tokens.size(); i++)
		{
			string& str = tokens[i];
			if (str != "+" && str != "-" && str != "*" && str != "/")
			{
				st.push(atoi(str.c_str()));
			}
			else
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				switch (str[0])
				{
				case '+':
					st.push(left + right);
					break;
				case '-':
					st.push(left - right);
					break;
				case '*':
					st.push(left * right);
					break;
				case '/':
					st.push(left / right);
					break;
				}
			}
			
		}
		
		return st.top();
	}
private:
	stack<int> st;
};

int main()
{
	vector<string> v;
	v.push_back("2");
	v.push_back("1");
	v.push_back("+");
	v.push_back("3");
	v.push_back("*");
	Solution s;
	cout << s.evalRPN(v) << endl;
}