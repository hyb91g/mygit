#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict)
{
	if (s.empty() || dict.empty())
		return false;

	//�ֵ����������
	int max_size = 0;
	for (auto e : dict)
	{
		if (e.size() > max_size)
			max_size = e.size();
	}

	//��ʼ��
	vector<bool> can_break(s.size() + 1, false);
	can_break[0] = true;

	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			//�Ӵ����ȴ�������ʳ��Ⱦ�����
			if (i - j > max_size)
				break;
			// F(i): true{j <i && F(j) && substr[j, i - j]���ڴʵ����ҵ�} OR false
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