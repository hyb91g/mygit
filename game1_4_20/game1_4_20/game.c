#include<string.h>

#include"game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', sizeof(board[0][0]) * row * col);
}

void print_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != row - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i != col - 1)
		{
			for (j = 0; j < row; j++)
			{
				printf("---");
				if (j != row - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}	
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家走\n");
		printf("请输入你要下棋的坐标：");
		scanf_s("%d %d", &x, &y);

		if (((x > 0) && (x <= row)) && ((y > 0) && (y <= col)))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("输入的坐标已有棋子，请重新输入！\n");
			}
		}
		else
		{
			printf("输入棋子的坐标有误，请重新输入！\n");
		}
	}
}

void computer_board(char board[ROW][COL], int row, int col)
{
	printf("电脑走\n");
	while (1)
	{
		int x = rand() % row;    //srand((unsigned int)(time(NULL))
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
}
static int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char is_win(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	for (x = 1; x < row - 1; x++)
	{
		for (y = 0; y < col; y++)
		{
			if ((board[x][y] == board[x - 1][y]) && (board[x][y] == board[x + 1][y]) && board[x][y] != ' ')
			{
				return board[x][y];
			}
		}
	}
	for (x = 0; x < row; x++)
	{
		for (y = 1; y < col - 1; y++)
		{
			if ((board[x][y] == board[x][y - 1]) && (board[x][y] == board[x][y + 1]) && board[x][y] != ' ')
			{
				return board[x][y];
			}
		}
	}

	for (x = 1; x < row - 1; x++)
	{
		for (y = 1; y < col - 1; y++)
		{
			if (((board[x][y] == board[x - 1][y - 1]) && (board[x][y] == board[x + 1][y + 1]) && board[x][y] != ' ')
				|| ((board[x][y] == board[x - 1][y + 1]) && (board[x][y] == board[x + 1][y - 1])) && board[x][y] != ' ')
				return board[x][y];
		}
	}
	if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';   //表示棋盘满了
	}
}
