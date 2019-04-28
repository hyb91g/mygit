#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	const char *cur = str.c_str();
	const char *ccur = cur;
	const char *ret = nullptr;
	int rcount = 0;
	int count = 1;
	while (ccur)
	{
		while (*ccur >= '0' && *ccur <= '9')
		{
			if (*(ccur + 1) == *ccur + 1)
			{
				++count;
				ccur += 1;
			}
			else
			{
				if (rcount < count)
				{
					rcount = count;
					ret = cur;
				}
				count = 1;
				cur = ccur + 1;
				ccur = cur;
			}
		}
		if (*cur == 0)
			break;
		if (*cur <= '0' && *cur >= '9')
			cur++;
		else
			cur = ccur + 1;

		ccur = cur;
	}

	cout << str.substr(str.find(ret), rcount) << endl;
	return 0;
}