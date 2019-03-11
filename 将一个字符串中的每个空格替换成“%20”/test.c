//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.

#include <stdio.h>
#include <string.h>

void replaceSpace(char *str, int length) {
	int count = 0;
	int i = 0;
	for (; i < length; i++) {
		if (str[i] == ' ') {
			count++;
		}
	}
	if (count == 0) {
		return;
	}
	int newlength = length + count * 2;

	int tail = newlength - 1;
	int sectail = length - 1;

	str[tail] = '\0';

	while (1) {
		if (str[sectail] == ' ') {
			str[tail--] = '0';
			str[tail--] = '2';
			str[tail--] = '%';
			sectail--;
			count--;
			if (count == 0) {
				return;
			}
		}
		else {
			str[tail--] = str[sectail--];
		}
	}


}
int main()
{
	char str[100] = "fdsfsdfsf ";
	replaceSpace(str, strlen(str) + 1);
	printf("%s", str);
	return 0;
}