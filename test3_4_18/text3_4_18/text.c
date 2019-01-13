//杨辉三角形


#include<stdio.h>
#include<stdlib.h>

int triangle(int i, int j)
{
	if (j == 1 || j == i + 1)
	{
		return 1;
	}
	return triangle(i - 1, j - 1) + triangle(i - 1, j);
}
int main()
{
	int i = 0, j = 0;
	int line = 0;
	printf("请输入行数：");
	scanf_s("%d", &line);
	for (i = 0; i < line; i++)
	{
		for (j = 1; j <= i + 1; j++)
		{
			printf("%d  ", triangle(i, j));
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

