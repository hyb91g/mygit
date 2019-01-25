//使用可变参数，实现函数，求函数参数的最大值。

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

int Max(int n, ...)
{
	va_list arg;
	int i = 0;
	va_start(arg, n);
	int max = va_arg(arg, int);

	for (i = 1; i < n; i++)
	{
		int tmp = va_arg(arg, int);
		if (max < tmp)
		{
			max = tmp;
		}
	}
	va_end(arg);
	return max;
}
int main()
{
	int max = Max(5, 3, 2, 4, 5, 7);
	printf("%d\n", max);
	system("pause");
	return 0;
}