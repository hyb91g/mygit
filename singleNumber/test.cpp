//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//
//˵����
//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����


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
			for (int j = 0; j < nums.size(); j++)  //ȡ�������ĵ�iλ����ret
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