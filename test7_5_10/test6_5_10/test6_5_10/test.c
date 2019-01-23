//递归和非递归分别实现求n的阶乘

#include<stdio.h>
#include<stdlib.h>

int fac(int n)
{
	if (n == 1)
		return 1;
	else
	{
		return n * fac(n - 1);
	}
}

int fac(int n)
{
	int i = 0;
	int sum = 1;
	for (i = 1; i <= n; i++)
	{
		sum *= i;
	}
	return sum;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf_s("%d", &n);
	ret = fac(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}