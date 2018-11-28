//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int arr[] = {0};
	int i = 0;
	scanf_s("%d", &a);
	while (a > 0)
	{
		for (i = 31; i >= 0; i--)
		{
			arr[i] = a % 2;
			a = a / 2;
		}
	}
	printf("偶数位：");
	for (i = 0; i < 32; i+=2)
	{
		printf("%d", arr[i]);
	}
	printf("\n奇数位：");
	for (i = 1; i < 31; i+=2)
	{
		printf("%d", arr[i]);
	}
	printf("\n二进制：");
	for (i = 0; i < 32; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}