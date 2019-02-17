//给定两个整形变量的值，将两个值的内容进行交换。

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
