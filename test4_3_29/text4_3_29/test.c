//��дһ���������ӱ�׼�����ȡCԴ���룬����֤���еĻ����Ŷ���ȷ�ĳɶԳ��֡�


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int count = 0;
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '{')
			count++;
		if (ch == '}' && count == 0)
		{
			printf("��ƥ��\n");
			return 0;
		}
		if (ch == '}' && count != 0)
		count--;
	}
	
	if (count == 0)
		printf("ƥ��\n");
	else
		printf("��ƥ��\n");
	system("puase");
	return 0;
}