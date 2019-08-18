#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict)
{
	if (s.empty() || dict.empty())
		return false;

	//字典中最长单词数
	int max_size = 0;
	for (auto e : dict)
	{
		if (e.size() > max_size)
			max_size = e.size();
	}

	//初始化
	vector<bool> can_break(s.size() + 1, false);
	can_break[0] = true;

	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			//子串长度大于最长单词长度就跳过
			if (i - j > max_size)
				break;
			// F(i): true{j <i && F(j) && substr[j, i - j]能在词典中找到} OR false
			if (can_break[j] &&  dict.find(s.substr(j, i - j)) != dict.end())
			{
				can_break[i] = true;
				break;
			}
		}
	}
	return can_break[s.size()];
}

int main()
{
	string str = "leedcode";
	unordered_set<string> dict = { "leed", "code" };
	cout << wordBreak(str, dict) << endl;
	return 0;
}