#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void sort(vector<int>& v)
	{
		int size = v.size();
		for (int i = (size - 2) / 2; i >= 0; i--)
		{
			AdjustDown(v, size, i);
		}
		while (size)
		{
			swap(v[0], v[size - 1]);
			size--;
			AdjustDown(v, size, 0);
		}
	}
	void AdjustDown(vector<int>& v, int size, int i)
	{
		int par = i;
		int chi = par * 2 + 1;

		while (chi < size)
		{
			if (chi + 1 < size && v[chi] < v[chi + 1])  //´ó¶Ñ£ºÉýÐò
			//if (chi + 1 < size && v[chi] > v[chi + 1])  //Ð¡¶Ñ£º½µÐò
				chi++;

			if (v[chi] > v[par]) //´ó¶Ñ£ºÉýÐò
			//if (v[chi] < v[par]) //Ð¡¶Ñ£º½µÐò
			{
				swap(v[chi], v[par]);
				par = chi;
				chi = par * 2 + 1;
			}
			else
				break;
		}
	}
	//void AdjustUp(vector<int>& v, int i)
	//{
	//	int chi = i;
	//	int par = (chi - 1) / 2;

	//	while (chi > 0)
	//	{
	//		if (v[chi] > v[par])
	//		{
	//			swap(v[chi], v[par]);
	//			chi = par;
	//			par = (chi - 1) / 2;
	//		}
	//		else
	//			break;
	//	}
	//}
};

int main()
{
	vector<int> v;
	v.push_back(15);
	v.push_back(4);
	v.push_back(1);
	v.push_back(8);
	v.push_back(3);
	v.push_back(2);
	Solution s;
	s.sort(v);
	return 0;
}