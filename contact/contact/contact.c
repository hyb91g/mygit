#include "contact.h"

static int FindPeople(pContact pc, char name[])
{
	unsigned int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->date[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void CheckContact(pContact pc)
{
	if (pc->capacity == pc->sz)
	{
		pPeoInfo ptr = realloc(pc->date, (pc->capacity += 2) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->date = ptr;
		}
		printf("增容成功\n");
	}
}

void LoadContact(pContact pc)
{
	FILE *pfRead = fopen(FILENAME, "r");
	PeoInfo tmp = { 0 };
	if (pfRead == NULL)
	{
		perror("open file for raed");
		exit(EXIT_FAILURE);
	}
	//载入
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckContact(pc);
		pc->date[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

void InitContact(pContact pc)
{
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->date = (pPeoInfo)calloc(pc->capacity, sizeof(PeoInfo));
	if (pc->date == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	//加载通讯录
	LoadContact(pc);

}

void SaveContact(pContact pc)
{
	FILE *pfWrite = fopen(FILENAME, "w");
	unsigned int i = 0;
	if (pfWrite == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->date + i, sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}

void DestoryContact(pContact pc)
{
	//保存通讯录
	SaveContact(pc);

	free(pc->date);
	pc->date = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	printf("销毁通讯录\n");
}

void AddContact(pContact pc)
{
	//if (pc->sz == MAX)
	//{
	//	printf("通讯录已满\n");
	//	return;
	//}

	CheckContact(pc);
	printf("请输入添加人的姓名：");
	scanf("%s", pc->date[pc->sz].name);
	printf("请输入添加人的性别：");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入添加人的年龄：");
	scanf("%hd", &(pc->date[pc->sz].age));
	printf("请输入添加人的电话：");
	scanf("%lld", &(pc->date[pc->sz].phone));
	printf("请输入添加人的地址：");
	scanf("%s", pc->date[pc->sz].address);

	pc->sz++;
	printf("添加成功\n");
}

void DelContact(pContact pc)
{
	unsigned int i = 0;
	char name[MAX_NAME] = { 0 };
	int ret = 0;
	if (pc->sz == 0)
	{
		printf("没有信息可以删除\n");
		return;
	}
	printf("请输入想要删除人的名字：");
	scanf("%s", name);
	ret = FindPeople(pc, name);
	if (ret == -1)
	{
		printf("删除的人不存在\n");
		return;
	}
	else
	{
		for (i = ret; i < pc->sz-1; i++)
		{
			pc->date[i] = pc->date[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");

	}
}

void SearchContact(pContact pc)
{
	char name[MAX_NAME] = { 0 };
	int ret = 0;
	printf("请输入想要查找人的名字：");
	scanf("%s", name);
	ret = FindPeople(pc, name);
	if (ret == -1)
	{
		printf("没有此人信息\n");
		return;
	}
	else
	{
		printf("姓名\t性别\t年龄\t地址\t电话\n");
		printf("%-s\t%-s\t%-hd\t%-s\t%-lld\n",
			pc->date[ret].name,
			pc->date[ret].sex,
			pc->date[ret].age,
			pc->date[ret].address,
			pc->date[ret].phone);
	}
}

void ShowContact(pContact pc)
{
	unsigned int i = 0;
	printf("姓名\t性别\t年龄\t地址\t电话\n");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-s\t%-s\t%-hd\t%-s\t%-lld\n",
			pc->date[i].name,
			pc->date[i].sex,
			pc->date[i].age,
			pc->date[i].address,
			pc->date[i].phone);
	}
}


void ModifyContact(pContact pc)
{
	int ret = 0;
	int i = 0;
	char name[MAX_NAME] = { 0 };
	printf("请输入想要修改的人的姓名：");
	scanf("%s", name);
	ret = FindPeople(pc, name);
	if (ret == -1)
	{
		printf("修改的人不存在\n");
		return;
	}
	else
	{
		int input = 0;
		printf("1.姓名 2.性别 3.年龄 4.电话 5.住址\n");
		printf("请选择想要修改的内容：");
		scanf("%d", &input);
		if (input == 1)
		{
			char names[MAX_NAME] = { 0 };
			scanf("%s", names);
			strcpy(pc->date[ret].name, names);
		}
		else if (input == 2)
		{
			char sexs[MAX_SEX] = { 0 };
			scanf("%s", sexs);
			strcpy(pc->date[ret].sex, sexs);
		}
		else if (input == 3)
		{
			short ages = 0;
			scanf("%hd", &ages);
			pc->date[ret].age = ages;
		}
		else if (input == 4)
		{
			long long phones = 0;
			scanf("%lld", &phones);
			pc->date[ret].phone = phones;
		}
		else if (input == 5)
		{
			char addresss[MAX_ADDRESS] = { 0 };
			scanf("%s", addresss);
			strcpy(pc->date[ret].address, addresss);
		}
		else
		{
			printf("输入错误！\n");
		}
		if (input >= 1 && input <= 5)
		{
			printf("修改成功！\n");
		}
	}
}

void EmptyContact(pContact pc)
{
	memset(pc->date, 0, sizeof(pc->date));
	pc->sz = 0;
	printf("通讯录已清空\n");
}

void SortContact(pContact pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录中没有信息\n");
		return;
	}
	unsigned int i = 0;
	unsigned int j = 0;
	PeoInfo tmp = { {0}, {0}, {0}, 0, 0 };
	for (i = 0; i < (pc->sz); i++)
	{
		for (j = 0; j < (pc->sz - i - 1); j++)
		{
			if (strcmp(pc->date[j].name, pc->date[j + 1].name) > 0)
			{
				tmp = pc->date[j];
				pc->date[j] = pc->date[j + 1];
				pc->date[j + 1] = tmp;
			}
		}
	}
	printf("排序成功\n");
}