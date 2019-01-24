//使用可变参数，实现函数，求函数参数的平均值。

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int average(int n, ...)
{
	va_list arg;
	int i = 0;
	int sum = 0;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);
	}
	va_end(arg);
	return sum / n;
}
int main()
{
	int ret = average(3, 5, 6, 7);
	printf("%d\n", ret);
	ret = average(7, 1, 2, 3, 4, 5, 6, 7);
	printf("%d\n", ret);

	system("pause");
	return 0;
}