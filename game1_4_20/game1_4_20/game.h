#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 5
#define COL 5

void init_board(char board[ROW][COL], int row, int col);
void print_board(char board[ROW][COL], int row, int col);
void player_move(char board[ROW][COL], int row, int col);
void computer_board(char board[ROW][COL], int row, int col);
char is_win(char board[ROW][COL], int row, int col);

enum OPTION
{
	EXIT,
	PLAY
};
#endif // ! __GAME_H__
