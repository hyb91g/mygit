#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

void Temp(char *left, char *right)
{
	while (left < right)
	{
		char c = *left;
		*left = *right;
		*right = c;

		left++;
		right--;
	}
}

void Invert(char* s)
{
	char *cur = s;
	char *ccur = cur;
	while (ccur)
	{
		while (*ccur != ' ' && *ccur != '\0')
		{
			ccur++;
		}
		Temp(cur, ccur - 1);
		if (*ccur == '\0')
			break;
		cur = ccur + 1;
		ccur = cur;
	}
	Temp(s, ccur - 1);
}

int main()
{
	char a[100] = { 0 };
	cin.getline(a, 100);
	Invert(a);
	cout << a << endl;

	return 0;
}