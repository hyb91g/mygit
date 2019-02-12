#ifndef __MAZE_H__
#define __MAZE_H__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define X 6


typedef struct Pos
{
	int _row;
	int _col;
}Pos;

void GetMazePath(Pos entry, Pos exit);
int CheckAccess(Pos next, Pos);

///////////////////////////////////////////////////////////////
typedef Pos DateType;
#define N 10

typedef struct Stack
{
	DateType* _a;
	int _top; //Õ»¶¥
	int _capacity; //ÈÝÁ¿
}Stack, *pStack;

void StackInit(pStack ps);
void StackDestory(pStack ps);

void StackPush(pStack ps, DateType x);
void StackPop(pStack ps);
DateType StackTop(pStack ps);
int StackEmpty(pStack ps);
int StackSize(pStack ps);

//void MazePrint();
//int MazeGetPath(Pos entry);
//void MazeGetPathR(Pos entry);
//int MazeCheckIsAccess(Pos pos);
//Stack shortPath;
//void MazeGetShortPath(Pos entry, Stack* path);


#endif // !__MAZE_H__


