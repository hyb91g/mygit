#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("***** 1.play   0.exit *****\n");
	printf("***************************\n");
}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);
	SetMine(mine, ROWS, COLS, EASY_COUNT);
	PrintBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((uint)time(NULL));
	do
	{
		menu();
		printf("请选择:> ");
		scanf_s("%d", &input);
		switch (input)
		{
		case START:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("选择有误，请重新选择");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}