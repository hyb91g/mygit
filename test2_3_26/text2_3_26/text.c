//����������ʱ���������������������ݣ�������

#include <stdio.h>

int main()
{
	int i = 3;
	int j = 9;
	
	i = i + j;
	j = i - j;
	i = i - j;
    printf("%d  %d",i,j);

	getchar();
	return 0;
}