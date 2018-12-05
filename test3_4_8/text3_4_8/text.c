//实现一个函数判断year是不是润年。

#include<stdio.h>
#include<stdlib.h>

int leap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}
int main()
{
	int year = 0;
	printf("输入年份:");
	scanf_s("%d", &year);
	int ret = leap(year);
	if (ret == 1)
	{
		printf("%d是闰年\n", year);
	}
	if (ret == 0)
	{
		printf("%d不是闰年\n", year);
	}
	system("pause");
	return 0;
}