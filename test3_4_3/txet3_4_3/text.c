//��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����

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
		printf("����������:");
		scanf_s("%s", arr2);
		if (strcmp(arr2, arr1) == 0)
			break;
	}
	if (i == 3)
	{
		printf("�˳�����\n");

	}
	else
		printf("��½�ɹ�\n");

	system("pause");
	return 0;
}