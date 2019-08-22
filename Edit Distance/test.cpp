//给定两个单词word1和word2，找到最小的修改步数，把word1转换成word2
//每一个操作记为一步
//允许在一个word上进行如下3种操作：
//a) 插入一个字符
//b) 删除一个字符
//c) 替换一个字符

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minDistance(string& s1, string& s2)
{
	if (s1.empty() || s2.empty()) {
		return max(s1.size(), s2.size());
	}

	int m = s1.size();
	int n = s2.size();
	vector<vector<int>> vv(m + 1, vector<int>(n + 1));
	for (int i = 0; i <= m; ++i)
	{
		vv[i][0] = i;
	}
	for (int i = 0; i <= n; ++i)
	{
		vv[0][i] = i;
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + 1;
			if (s1[i - 1] == s2[j - 1])
				vv[i][j] = min(vv[i - 1][j - 1], vv[i][j]);
			else
				vv[i][j] = min(vv[i - 1][j - 1] + 1, vv[i][j]);
		}
	}
	return vv[m][n];
}

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	cout << minDistance(s1, s2) << endl;
	return 0;
}