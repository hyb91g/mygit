#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//O(m*n)
//int backPackII(int m, vector<int> &A, vector<int> &V) 
//{
//	if (A.empty() || V.empty() || m < 1)
//		return 0;
//	int n = A.size();
//	vector<vector<int>> vv(n + 1, vector<int>(m + 1, 0));
//
//	for (int i = 1; i < n + 1; ++i)
//	{
//		for (int j = 1; j < m + 1; ++j)
//		{
//			if (A[i - 1] > j)  //装不下
//				vv[i][j] = vv[i - 1][j];
//			else
//			{
//				vv[i][j] = max(vv[i - 1][j - A[i - 1]] + V[i - 1], vv[i - 1][j]);
//			}
//		}
//	}
//	return vv[n][m];
//}

//O(m)
int backPackII(int m, vector<int> &A, vector<int> &V) 
{
	if (A.empty() || V.empty() || m < 1)
		return 0;

	int n = A.size();
	vector<int> v(m + 1, 0);

	for (int i = 0; i < n; ++i)
	{
		for (int j = m; j > 0; --j)
		{
			if (A[i] > j)
				v[j] = v[j];
			else
			{
				v[j] = max(v[j], v[j - A[i]] + V[i]);
			}
		}
	}
	return v[m];
}

int main()
{
	int n;
	cout << "输入数组大小：";
	cin >> n;
	vector<int> A(n);
	vector<int> V(n);
	cout << "输入数组A：";
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	cout << "输入数组V：";
	for (int i = 0; i < n; ++i)
	{
		cin >> V[i];
	}
	int m;
	cout << "输入背包大小：";
	cin >> m;
	
	cout << "最大价值：" << backPackII(m, A, V) << endl;
	return 0;
}