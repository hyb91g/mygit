#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#include<stdio.h>
#include<stdlib.h>

enum State
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
};

void DoNulState(FILE* pfIn, FILE* pfOut, enum State *ps);
void DoCState(FILE* pfIn, FILE* pfOut, enum State *ps);
void DoCPPState(FILE* pfIn, FILE* pfOut, enum State *ps);

void CommentConvert(FILE* pfIn, FILE* pfOut);

#endif // !__COMMENT_CONVERT_H__
