#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsPalindrome(string s)
{
	const char* left = s.c_str();
	const char* right = s.c_str() + s.size() - 1;
	while (left < right)
	{
		if (*left++ != *right--)
			return false;
	}
	return true;
}

int minCut(string& s)
{
	if (s.empty())
		return 0;
	const char* cur = s.c_str();
	vector<int> v(s.size() + 1);
	for (int i = 0; i < s.size()+1; ++i)
	{
		v[i] = i - 1;
	}
	for (int i = 1; i < s.size()+1; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (IsPalindrome(s.substr(j, i)))
			{
				v[i] = min(v[i], v[j] + 1);
			}
		}
	}
	return v[s.size()];

}

int main()
{
	string s;
	cin >> s;
	cout << minCut(s) << endl;
	return 0;
}