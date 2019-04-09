//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
//
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int i = 0; i < 32; i++)  
		{
			int mask = 1 << i;
			int count = 0;
			for (int j = 0; j < nums.size(); j++)  //取所有数的第i位赋给ret
			{
				if ((nums[j] & mask) != 0)
					count++;
			}
			if ((count % 3) != 0)
				ret |= mask;
		}
		return ret;
	}
};



int main()
{
	Solution s;
	vector<int> v(2, -2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(-3);
	v.push_back(1);
	v.push_back(-3);
	v.push_back(-3);
	v.push_back(-4);
	v.push_back(-2);



	cout << s.singleNumber(v) << endl;
	return 0;
}