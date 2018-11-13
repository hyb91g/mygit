//将三个数按从大到小输出

#include<stdio.h>
int main()
{
	int a, b, c;
	int d, e, f;
	scanf_s("%d %d %d", &a, &b, &c);
	if (a > b)
	{
		if (b > c)
		{
			d = a; e = b; f = c;
		}
		else
		{
			if (a > c)
			{
				d = a; e = c; f = b;
			}
			else
			{
				d = c; e = a; f = b;
			}
		}
	}
	else
	{
		if (a > c)
		{
			d = b; e = a; f = c;
		}
		else
		{
			if (b > c)
			{
				d = b; e = c; f = a;
			}
			else
			{
				d = c; e = b; f = a;
			}
		}
	}
	printf("%d, %d, %d\n", d, e, f);
	return 0;
}

