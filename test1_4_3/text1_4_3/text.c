//��ɲ�������Ϸ��


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("**************************************\n");
	printf("*************  1. play  **************\n");
	printf("*************  2. exit  **************\n");
	printf("**************************************\n\n");
}

void game()
{
	int random_num = rand() % 100 + 1;  // 0 ~ 100�����
	int input = 0;
	while(1)
	{
		printf("��������Ҫ�µ�����:");
		scanf_s("%d", &input);
		if (input > random_num)
		{
			printf("�´���\n");
		}
		else if (input < random_num)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n\n");
			break;
		}
	}
	
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));

	do
	{
		menu();
		printf("��ѡ��>:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			break;
		default:
			printf("������������ԣ�\n");
			break;
		}
	} while (input);
	
	system("pause");
	return 0;
}