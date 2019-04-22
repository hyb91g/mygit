//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ע����ַ����ɱ���Ϊ����Ч�ַ�����


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