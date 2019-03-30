//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
//要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		int flag = 1;
		for (auto c : str)
		{
			if ((c >= '0' && c <= '9')
				|| c == '+' || c == '-')
			{
				if (c == '+')
					flag = 1;
				if (c == '-')
					flag = -1;
			}
			else
				return 0;
		}
		int value = 0;
		for (auto c : str)
		{
			if (c == '+' || c == '-')
			{
				continue;
			}
			value *= 10;
			value += c - '0';

		}
		value *= flag;
		return value;
	}
};

int main()
{
	string s("-123");
	cout << Solution().StrToInt(s) << endl;
	return 0;
}