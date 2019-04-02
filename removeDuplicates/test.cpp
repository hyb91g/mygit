//����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�

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