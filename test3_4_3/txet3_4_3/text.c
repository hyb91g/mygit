//编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char arr1[] = "ssssss";
	char arr2[] = "";
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码:");
		scanf_s("%s", arr2);
		if (strcmp(arr2, arr1) == 0)
			break;
	}
	if (i == 3)
	{
		printf("退出程序\n");

	}
	else
		printf("登陆成功\n");

	system("pause");
	return 0;
}