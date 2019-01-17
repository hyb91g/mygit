//递归和非递归分别实现求第n个斐波那契数。
#include<stdio.h>
#include<stdlib.h>

//int fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fib(n - 1) + fib(n - 2);
//	}
//}
int fib(int n)
{
	int a = 1;
	int b = 1;
	int ret = 1;
	while (n>=3)
	{
		ret = a + b;
		a = b;
		b = ret;
		n--;
	}
	return ret;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf_s("%d", &n);
	ret = fib(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}