//ʹ�ú���ʵ���������Ľ�����

#include<stdio.h>
#include<stdlib.h>

int swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int x = 5, y = 10;
	swap(&x, &y);
	printf("x=%d  y=%d", x, y);
	system("pause");
	return 0;
}