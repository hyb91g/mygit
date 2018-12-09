//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

#include<stdio.h>
#include<stdlib.h>


int main()
{
	int A = 0, B = 0, C = 0, D = 0;
	int FD;
	int i = 0;
	for (i = 1; i <= 4; i++)
	{

		if (i == 1)
		{
			A = 1; C = 1; FD = 1; D = 0;
		}
		if (i == 2)
		{
			A = 0; C = 0; FD = 1; D = 0;
		}
		if (i == 3)
		{
			A = 0; C = 1; FD = 0; D = 0;
		}
		if (i == 4)
		{
			A = 0; C = 1; FD = 1; D = 0;
		}
		if (A + B + C + D + FD == 1 && FD == D)
			printf("A=%d B=%d C=%d D=%d\n", A, B, C, D);
	}
	system("pause");
	return 0;
}