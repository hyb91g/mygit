//ʵ��һ���������ж�һ�����ǲ���������

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int prime(int a)
{
	int i = 0;
	for (i = 2; i <= sqrt; i++)
	{
		if (a%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int a = 0;
	printf("����һ������");
	scanf_s("%d", &a);
	int ret = prime(a);
	if (ret == 1)
	{
		printf("%d������\n", a);
	}
	if (ret == 0)
	{
		printf("%d��������\n", a);
	}
	system("pause");
	return 0;
}