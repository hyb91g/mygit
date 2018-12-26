#include"game.h"

void menu()
{
	printf("             ��������Ϸ            \n");
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
			printf("��ϲ�㣬Ӯ�ˣ�\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
		computer_board(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret == 'O')
		{
			printf("����Ӯ�ˣ�\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ��\n");
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
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case PLAY:
			game();
			break;
		case EXIT:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
