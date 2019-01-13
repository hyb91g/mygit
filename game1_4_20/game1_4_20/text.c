#include"game.h"

void menu()
{
	printf("             三子棋游戏            \n");
	printf("\n");
	printf("***********************************\n");
	printf("*******       1. play       *******\n");
	printf("*******       0. exit       *******\n");
	printf("***********************************\n");
}

void game()
{
	int row = 0;
	int col = 0;
	char ret = '0';
	char board[ROW][COL] = { '0' };
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);
	while (1)
	{
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret == 'X')
		{
			printf("恭喜你，赢了！\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
		computer_board(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret == 'O')
		{
			printf("电脑赢了！\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
	}

}

int main()
{
	int input = 0;
	srand((unsigned int)(time(NULL)));
	menu();
	do
	{
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
