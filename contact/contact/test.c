//实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：
//姓名、性别、年龄、电话、住址
//
//提供方法：
//1. 添加联系人信息
//2. 删除指定联系人信息
//3. 查找指定联系人信息
//4. 修改指定联系人信息
//5. 显示所有联系人信息
//6. 清空所有联系人
//7. 以名字排序所有联系人

#include<stdio.h>
#include<stdlib.h>
#include "contact.h"

void menu()
{
	printf("******************************\n");
	printf("**** 1.Add        2.Del   ****\n");
	printf("**** 3.Search     4.Modify****\n");
	printf("**** 5.Show       6.Empty ****\n");
	printf("**** 7.Sort       0.Exit  ****\n");
	printf("******************************\n");
}

int main()
{
	int input = 1;
	Contact my_con;
	InitContact(&my_con);
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			AddContact(&my_con);
			break;
		case del:
			DelContact(&my_con);
			break;
		case search:
			SearchContact(&my_con);
			break;
		case modify:
			ModifyContact(&my_con);
			break;
		case show:
			ShowContact(&my_con);
			break;
		case empty:
			EmptyContact(&my_con);
			break;
		case sort:
			SortContact(&my_con);
			break;
		case EXIT:
			DestoryContact(&my_con);
			break;
		default:
			printf("输出错误！\n");
			break;
		}
	} while (input);
	
	system("pause");
	return 0;
}
