//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	scanf_s("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", i, j, i*j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}