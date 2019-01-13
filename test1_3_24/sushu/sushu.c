#include<stdio.h>
#include<math.h>
int main()
{
int i, j;
printf("100µ½200µÄËØÊı£º\n");

for (i = 100; i <= 200; i++)
{
	for (j = 2; j <= sqrt(i); j++)
	{
		if (i%j == 0)
			break;
	}

if (sqrt(i) < j)
	printf("%d  ", i);
}
printf("\n");
getchar();
return 0;
}