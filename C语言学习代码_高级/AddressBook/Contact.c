#define _CRT_SECURE_NO_WARNINGS	1
#include "Contact.h"


void InitContact(Contact* pc) 
{
	pc->sz = 0;
	// memset(); 内存设置
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满 无法添加\n");
		return;
	}
	// 增加一个人信息
	printf("请输入名字:> ");
	scanf("%s", pc->data[pc->sz].Name);
	printf("请输入年龄:> ");
	scanf("%d", &(pc->data[pc->sz].Age));
	printf("请输入性别:> ");
	scanf("%s", pc->data[pc->sz].Sex);
	printf("请输入手机号:> ");
	scanf("%s", pc->data[pc->sz].Tele);
	printf("请输入地址:> ");
	scanf("%s", pc->data[pc->sz].Addr);
	pc->sz++;
	printf("增加成功！\n");
}

void PrintContact(const Contact* pc)
{
	int i = 0;
	// 打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",pc->data[i].Name,
			pc->data[i].Age,
			pc->data[i].Sex,
			pc->data[i].Tele,
			pc->data[i].Addr
			);
	}
	return 0;
}

static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].Name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = {0};
	if (pc->sz == 0)
	{
		printf("通讯录为空 无需删除\n");
		return;
	}
	// 1. 查找要删除的人 
	// 2. 删除
	printf("请输入要删除人的名字:> \n");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	// 删除
	int i = 0;
	for (i = pos; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功 ！\n");
}

void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:> \n");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->data[pos].Name,
				pc->data[pos].Age,
				pc->data[pos].Sex,
				pc->data[pos].Tele,
				pc->data[pos].Addr
			);
	}
}

void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:> \n");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入名字:> ");
		scanf("%s", pc->data[pos].Name);
		printf("请输入年龄:> ");
		scanf("%d", &(pc->data[pos].Age));
		printf("请输入性别:> ");
		scanf("%s", pc->data[pos].Sex);
		printf("请输入手机号:> ");
		scanf("%s", pc->data[pos].Tele);
		printf("请输入地址:> ");
		scanf("%s", pc->data[pos].Addr);
		printf("修改成功！\n");
	}
}