//���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7

#include<stdio.h>
#include<stdlib.h>

int count_one_bits(int a)
{

	int count = 0;
	while (a > 0)
	{
		if (a % 2 == 1)
		{
			count++;
			a = a / 2;
		}
		if (a % 2 == 0)
		{
			a = a / 2;
		}
	}


	return count;
}

int main()
{
	int a = 0;
	int b = 0;
	int i = 0;
	int j = 0;
	scanf_s("%d %d", &i,&j);

	a = i ^ j;
	
	b = count_one_bits(a);
	printf("%d\n", b);
	system("pause");
	return 0;
}

