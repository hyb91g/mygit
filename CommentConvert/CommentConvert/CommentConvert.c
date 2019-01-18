#define _CRT_SECURE_NO_WARNINGS

#include"CommentConvert.h"

void DoNulState(FILE* pfIn, FILE* pfOut, enum State *ps)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case '/':
	{
		int second = fgetc(pfIn);
		switch (second)
		{
		case '*':
		{
			fputc('/', pfOut);
			fputc('/', pfOut);
			*ps = C_STATE;
		}
			break;
		case '/':
		{
			fputc(first, pfOut);
			fputc(second, pfOut);
			*ps = CPP_STATE;
		}
			break;
		default:
			fputc(first, pfOut);
			fputc(second, pfOut);
			break;
		}
	}
		break;
	case EOF:
		fputc(first, pfOut);
		*ps = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}

void DoCState(FILE* pfIn, FILE* pfOut, enum State *ps)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case '*':
	{
		int second = fgetc(pfIn);
		switch (second)
		{
		case '/':
		{
			int third = fgetc(pfIn);
			if (third == '\n')
			{
				fputc(third, pfOut);
				*ps = NUL_STATE;
			}
			else
			{
				ungetc(third, pfIn);
				fputc('\n', pfOut);
				*ps = NUL_STATE;
			}
		}
		break;
		//case '*':

		//	break;
		default:
			fputc(first, pfOut);
			break;
		}
	}
		break;
	case '\n':
		fputc(first, pfOut);
		fputc('/', pfOut);
		fputc('/', pfOut);
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}

void DoCPPState(FILE* pfIn, FILE* pfOut, enum State *ps)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case '\n':
	{
		fputc(first, pfOut);
		*ps = NUL_STATE;
	}
		break;
	case EOF:
		fputc(first, pfOut);
		*ps = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}

void CommentConvert(FILE* pfIn, FILE* pfOut)
{
	enum State state = NUL_STATE;
	while (state != END_STATE)
	{
		switch (state)
		{
		case NUL_STATE:
			DoNulState(pfIn, pfOut, &state);
			break;
		case C_STATE:
			DoCState(pfIn, pfOut, &state);
			break;
		case CPP_STATE:
			DoCPPState(pfIn, pfOut, &state);
			break;
		case END_STATE:
			break;
		default:
			break;
		}
	}
}
