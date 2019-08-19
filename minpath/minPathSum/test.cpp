#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int> > &grid)
{
	if (grid.empty())
		return -1;

	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int> > vv(grid);
	for (int i = 1; i < m; ++i)
	{
		vv[i][0] = vv[i - 1][0] + vv[i][0];
	}
	for (int j = 1; j < n; ++j)
	{
		vv[0][j] = vv[0][j - 1] + vv[0][j];
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + vv[i][j];
		}
	}
	return vv[m - 1][n - 1];
}

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int> > vv(m, vector<int>(n));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> vv[i][j];
		}
	}
	cout << minPathSum(vv) << endl;
	return 0;
}