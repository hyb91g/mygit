//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

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