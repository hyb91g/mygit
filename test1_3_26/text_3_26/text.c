//�����������α�����ֵ��������ֵ�����ݽ��н�����

#include<stdio.h>

int main ()
{
	int i = 5;
	int j = 12;
	int k = 0;

	k = i;
	i = j;
	j = k;
	
	printf("%d  %d", i, j);
	

	return 0;
}