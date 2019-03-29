//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
//假定该字符串只包含小写字母

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