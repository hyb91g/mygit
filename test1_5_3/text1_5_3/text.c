//调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。  


#include<stdio.h>
#include<stdlib.h>

void swap_arr(int arr[], int sz)
{
	int tmp = 0;
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		while (arr[left] % 2 == 1 && left < right)
		{
			left++;
		}
		while (arr[right] % 2 == 0 && left < right)
		{
			right--;
		}
		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d   ", arr[i]);
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap_arr(arr, sz);
	print_arr(arr, sz);
	system("pause");
	return 0;
}