//������A�е����ݺ�����B�е����ݽ��н�����������һ����

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[3] = { 1,2,3 }, b[3] = { 4,5,6 }, c = 0;
	int i = 0;
	for (i; i < 3; i++)
	{
		c = a[i];
		a[i] = b[i];
		b[i] = c;
	}
	for (i=0; i < 3; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	for (i=0; i < 3; i++)
		printf("%d ", b[i]);
	printf("\n");

	system("pause");
	return 0;
}