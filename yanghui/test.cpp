//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
//输入 : 5
//输出 :
//	[
//		[1],
//		[1, 1],
//		[1, 2, 1],
//		[1, 3, 3, 1],
//		[1, 4, 6, 4, 1]
//	]
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {

	vector<vector<int>> v;
	v.resize(numRows);

	for (int i = 0; i < numRows; i++)
	{
		v[i].resize(i + 1, 1);
	}
	for (int i = 2; i < numRows; i++)
	{
		for (int j = 1; j < i; j++)
		{
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
		}
	}

	return v;
}


int main()
{
	vector<vector<int>> v = generate(5);

	return 0;
}