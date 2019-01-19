//实现一个函数，判断一个数是不是素数。

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
	printf("输入一个数：");
	scanf_s("%d", &a);
	int ret = prime(a);
	if (ret == 1)
	{
		printf("%d是素数\n", a);
	}
	if (ret == 0)
	{
		printf("%d不是素数\n", a);
	}
	system("pause");
	return 0;
}
