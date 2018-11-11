//不允许创建临时变量，交换两个数的内容（附加题

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