#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
	if (obstacleGrid.empty())
		return -1;
	if (obstacleGrid[0][0] == 1)
		return 0;
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int> > vv(m, vector<int>(n, 1));
	for (int i = 0; i < n; ++i)
	{
		if (obstacleGrid[0][i] == 1)
			vv[0][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		if (obstacleGrid[i][0] == 1)
			vv[i][0] = 0;
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (obstacleGrid[i][j] == 1)
				vv[i][j] = 0;
			else
			{
				vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
			}
		}
	}
	return vv[m - 1][n - 1];
}

int main()
{
	vector<vector<int> > vv = { {0,0,0},{0,1,0},{0,0,0} };
	cout << uniquePathsWithObstacles(vv) << endl;
	return 0;
}