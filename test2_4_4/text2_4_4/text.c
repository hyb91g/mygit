//��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�

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
	printf("ż��λ��");
	for (i = 0; i < 32; i+=2)
	{
		printf("%d", arr[i]);
	}
	printf("\n����λ��");
	for (i = 1; i < 31; i+=2)
	{
		printf("%d", arr[i]);
	}
	printf("\n�����ƣ�");
	for (i = 0; i < 32; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}