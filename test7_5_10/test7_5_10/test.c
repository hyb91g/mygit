//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ

#include<stdio.h>
#include<stdlib.h>


void Digit(int n)
{
	if (n > 9)
	{
		Digit(n / 10);
	}
	printf("%d  ", n % 10);
}
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	Digit(n);
	system("pause");
	return 0;
}