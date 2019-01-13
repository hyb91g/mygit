//写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回 - 1.（折半查找）

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int a;
	int mid = 0;
	printf("请输入你想要找的数字:");
	scanf_s("%d", &a);
	while (right >= left)
	{
		mid = left + (right - left) / 2;
		if (a > arr[mid])
		{
			left = mid + 1;
		}
		else if (a < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			printf("找到了，下标是%d\n", mid);
			break;
		}
	}
	if (right < left)
	{
		printf("-1\n");
	}
	system("pause");
	return 0;
}