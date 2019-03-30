//��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�����string����������Ҫ��ʱ����0)��
//Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��

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