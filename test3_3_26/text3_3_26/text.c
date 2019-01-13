//求10 个整数中最大值。

#include<stdio.h>

int main()
{
	int i = 0, arr[10] = { 0 }, max = 0;
	printf("输入十个整数：\n");
	for (i; i < 10; i++)
		scanf_s("%d", &arr[i]);
	max = arr[0];
	for (i = 0; i < 10; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}