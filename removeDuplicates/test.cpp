//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	vector<int>::iterator tmp = nums.begin();
	vector<int>::iterator cur = tmp;
	vector<int>::iterator cmp = ++tmp;
	int count = 1;
	while (cmp != nums.end())
	{
		while (*cur == *cmp)
		{
			cmp++;
			if (cmp == nums.end())
				break;
		}
		cur++;
		if (cmp != nums.end())
		{
			count++;
			*cur = *cmp;
		}
	}
	return count;

}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);

	cout << removeDuplicates(v) << endl;
	return 0;
}