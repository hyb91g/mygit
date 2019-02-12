#include"Maze.h"

int maze[X][X] =
{
{ 0,0,0,0,0,0 },
{ 0,0,1,1,1,0 },
{ 0,0,1,0,1,0 },
{ 0,0,1,1,1,0 },
{ 0,0,1,0,1,1 },
{ 0,0,1,0,0,0 },
};

int count = 0;

int CheckAccess(Pos next, Pos cur)
{
	if (next._row >= 0 && next._row < X && next._col >= 0 && next._col < X &&
		(maze[next._row][next._col] == 1 || maze[next._row][next._col] - 1 > maze[cur._row][cur._col]))
		return 1;
	else
		return 0;
}

void GetMazePath(Pos entry, Pos exit)
{
	Stack path;
	StackInit(&path);
	maze[entry._row][entry._col] = 2;
	StackPush(&path, entry);
	while (StackEmpty(&path) != 0)
	{
		Pos cur = StackTop(&path);
		//
		//if (cur._row == exit._row &&
		//	cur._col == exit._col)
		//{
		//	//����
		//	StackDestory(&path);
		//	return 1;

		//	//count = StackSize(&path);
		//	
		//}
		if (cur._col == X-1)
		{
			if ((StackSize(&path) < count) || (count == 0))
			{
				count = StackSize(&path);
			}
		}
		Pos next;

		//��
		next = cur;
		next._row -= 1;
		if (CheckAccess(next, cur))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//��
		next = cur;
		next._row += 1;
		if (CheckAccess(next, cur))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//��
		next = cur;
		next._col -= 1;
		if (CheckAccess(next, cur))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//��
		next = cur;
		next._col += 1;
		if (CheckAccess(next, cur))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		//����
		StackPop(&path);
	}
	//return 0;
}

int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < X; j++)
			printf("%2d ", maze[i][j]);
		printf("\n");
	}
	printf("\n");

	Pos entry, exit;
	entry._row = 5;
	entry._col = 2;
	exit._row = 4;
	exit._col = 5;

	//if (GetMazePath(entry, exit))
	//{
	//	printf("��·\n");
	//}
	GetMazePath(entry, exit);
	printf("����·���ȣ�%d\n", count);

	for (i = 0; i < X; i++)
	{
		for (j = 0; j < X; j++)
			printf("%-2d ", maze[i][j]);
		printf("\n");
	}
	printf("\n");
	return 0;
}