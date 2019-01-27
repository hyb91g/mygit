//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//找出这两个数字，编程实现。

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[] = { 1,2,3,4,5,3,2,1 };
	int i = 0;
	int sum = 0;
	int count = 0;
	int a = 0;
	int b = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		sum ^= arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (((sum >> i) & 1) == 1)
		{
			count = i;
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> count) & 1) == 1)
		{
			a ^= arr[i];
		}
		if (((arr[i] >> count) & 1) == 0)
		{
			b ^= arr[i];
		}
	}
	printf("%d  %d\n", a, b);
		
	system("pause");
	return 0;
}