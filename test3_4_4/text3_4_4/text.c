//���һ��������ÿһλ��

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	printf("����һ����:");
	scanf_s("%d", &i);
	while (i)
	{
		if (i < 0)
		{
			i = -i;
		}
		printf("%d\n", i % 10);
		i /= 10;
	}

	system("pause");
	return 0;
}