#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void sort(vector<int>& v)
	{
		int gap = v.size() / 2;
		while (gap >= 1)
		{
			for (size_t i = gap; i < v.size(); i++)
			{
				int temp = v[i];
				int j = 0;
				for (j = i - gap; j >= 0 && v[j] > temp; j = j - gap)
				{
					v[j + gap] = v[j];
				}
				v[j + gap] = temp;
			}
			gap /= 2;
		}
	}
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