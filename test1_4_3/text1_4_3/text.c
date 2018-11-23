//完成猜数字游戏。


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
	int random_num = rand() % 100 + 1;  // 0 ~ 100随机数
	int input = 0;
	while(1)
	{
		printf("请输入你要猜的数字:");
		scanf_s("%d", &input);
		if (input > random_num)
		{
			printf("猜大了\n");
		}
		else if (input < random_num)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n\n");
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
		printf("请选择>:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			break;
		default:
			printf("输入错误，请重试！\n");
			break;
		}
	} while (input);
	
	system("pause");
	return 0;
}