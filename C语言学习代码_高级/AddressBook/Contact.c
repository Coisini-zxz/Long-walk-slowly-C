#define _CRT_SECURE_NO_WARNINGS	1
#include "Contact.h"


void InitContact(Contact* pc) 
{
	pc->sz = 0;
	// memset(); �ڴ�����
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼���� �޷����\n");
		return;
	}
	// ����һ������Ϣ
	printf("����������:> ");
	scanf("%s", pc->data[pc->sz].Name);
	printf("����������:> ");
	scanf("%d", &(pc->data[pc->sz].Age));
	printf("�������Ա�:> ");
	scanf("%s", pc->data[pc->sz].Sex);
	printf("�������ֻ���:> ");
	scanf("%s", pc->data[pc->sz].Tele);
	printf("�������ַ:> ");
	scanf("%s", pc->data[pc->sz].Addr);
	pc->sz++;
	printf("���ӳɹ���\n");
}

void PrintContact(const Contact* pc)
{
	int i = 0;
	// ��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ�� ����ɾ��\n");
		return;
	}
	// 1. ����Ҫɾ������ 
	// 2. ɾ��
	printf("������Ҫɾ���˵�����:> \n");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	// ɾ��
	int i = 0;
	for (i = pos; i < pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ� ��\n");
}

void SearchContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:> \n");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸��˵�����:> \n");
	scanf("%s", &name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("����������:> ");
		scanf("%s", pc->data[pos].Name);
		printf("����������:> ");
		scanf("%d", &(pc->data[pos].Age));
		printf("�������Ա�:> ");
		scanf("%s", pc->data[pos].Sex);
		printf("�������ֻ���:> ");
		scanf("%s", pc->data[pos].Tele);
		printf("�������ַ:> ");
		scanf("%s", pc->data[pos].Addr);
		printf("�޸ĳɹ���\n");
	}
}