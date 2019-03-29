//����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
//�ٶ����ַ���ֻ����Сд��ĸ

#include <iostream>
#include<string>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		int hashtable[26] = { 0 };
		for (auto c : s)
		{
			hashtable[c - 'a']++;
		}
		for (size_t i = 0; i < s.size(); i++)
		{
			if (hashtable[s[i] - 'a'] == 1)
				return i+1;
		}
		return -1;
	}
};
int main()
{
	string s;
	cin >> s;
	cout << Solution().firstUniqChar(s) << endl;
	return 0;
}