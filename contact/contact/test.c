//ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
//�������Ա����䡢�绰��סַ
//
//�ṩ������
//1. �����ϵ����Ϣ
//2. ɾ��ָ����ϵ����Ϣ
//3. ����ָ����ϵ����Ϣ
//4. �޸�ָ����ϵ����Ϣ
//5. ��ʾ������ϵ����Ϣ
//6. ���������ϵ��
//7. ����������������ϵ��

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
		printf("��ѡ��->");
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
			printf("�������\n");
			break;
		}
	} while (input);
	
	system("pause");
	return 0;
}
