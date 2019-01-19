//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19

#include<stdio.h>
#include<stdlib.h>

int DigitSum(int n)
{
	if (n != 0)
	{
		return n % 10 + DigitSum(n / 10);
	}
	else
		return 0;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf_s("%d", &n);
	if (n < 0)
	{
		printf("负数\n");
		system("pause");
		return 0;
	}
	ret = DigitSum(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
