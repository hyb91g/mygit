#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
	if (triangle.empty())
		return 0;
	int size = triangle.size();
	vector<vector<int>> vv(triangle);
	for (int i = size - 2; i >= 0; --i)
	{
		for (int j = 0; j <= i; j++)
		{
			vv[i][j] = min(vv[i + 1][j], vv[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return vv[0][0];
}

int main()
{
	//  [2],
	//	[3, 4],
	//	[6, 5, 7],
	//	[4, 1, 8, 3]
	vector<vector<int>> vv = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
	cout << minimumTotal(vv) << endl;
	return 0;
}