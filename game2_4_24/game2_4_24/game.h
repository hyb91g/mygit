#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef unsigned int uint;
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

enum OPTION
{
	EXIT,
	START
};

enum MINE_COUNT
{
	EASY_COUNT=10
};

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int rows, int cols, int count);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);

#endif // ! __GAME_H__