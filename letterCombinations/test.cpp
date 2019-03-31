#include<iostream>
#include<string>
#include<vector>

using namespace std;

string arr[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution {
public:
	void combineStr(string digits, int index, vector<string>& ret, const string& str)
	{
		if (index == digits.size())  
		{
			ret.push_back(str);
			return;
		}

		string letters = arr[digits[index] - '0'];  //拿出对应数组下标所对应的字符串
		for (size_t i = 0; i < letters.size(); i++)
		{
			combineStr(digits, index + 1, ret, str + letters[i]); 
			//index 不能使用 ++ （递归回来时不能改变index的值）
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		if (digits.size() == 0)
		{
			return ret;
		}

		int index = 0;   
		string str;
		combineStr(digits, index, ret, str);
		return ret;	
	}
};

int main()
{
	string digits("234");
	Solution s;
	vector<string> ret = s.letterCombinations(digits);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
}