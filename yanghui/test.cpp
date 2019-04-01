//����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�
//���� : 5
//��� :
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