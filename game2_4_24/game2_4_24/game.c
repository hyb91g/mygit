#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int rows, int cols, int count)
{
	//int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % (rows - 2) + 1;
		int y = rand() % (cols - 2) + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int count = 0;
	while (win < row*col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:> ");
		scanf_s("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				if (win != 0)
				{
					printf("你被炸死了\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				else
				{
					count = GetMineCount(mine, x, y);
					show[x][y] = count + '0';
					PrintBoard(show, ROW, COL);
					SetMine(mine, ROWS, COLS, 1);
					mine[x][y] = '0';
					PrintBoard(mine, ROW, COL);
					win++;
				}
			}
			else
			{
				count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				PrintBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("输入的坐标有误，请重新输入\n");
		}
	}
	if (win >= row * row - EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
	}
}