//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ����磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19

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
		printf("����\n");
		system("pause");
		return 0;
	}
	ret = DigitSum(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
