//ʵ��һ�������ж�year�ǲ������ꡣ

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
	printf("�������:");
	scanf_s("%d", &year);
	int ret = leap(year);
	if (ret == 1)
	{
		printf("%d������\n", year);
	}
	if (ret == 0)
	{
		printf("%d��������\n", year);
	}
	system("pause");
	return 0;
}