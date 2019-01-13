//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。

#include<stdio.h>
#include<stdlib.h>

void init(int arr[])
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d   ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[])
{
	int j = 0;
	for (int j = 4; j >= 0; j--)
	{
		printf("%d   ", arr[j]);
	}
	printf("\n");
}

void empty(int arr[])
{
	int k = 0;
	for (k = 0; k < 5; k++)
	{
		arr[k] = 0;
	}
	for (k = 0; k < 5; k++)
	{
		printf("%d   ", arr[k]);
	}
	printf("\n");
}

int main()
{
	int arr[5] = { 0 };
	init(arr);
	reverse(arr);
	empty(arr);

	system("pause");
	return 0;
}