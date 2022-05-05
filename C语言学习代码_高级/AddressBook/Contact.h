#pragma once
#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_TELE 20
#define MAX_ADDR 20
#define MAX 1000
#define DEFAULT_SZ 3
#define INT_SZ 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




// ���͵Ķ���
typedef struct PeoInfo
{
	char Name[MAX_NAME];
	char Sex[MAX_SEX];
	int Age;
	char Tele[MAX_TELE];
	char Addr[MAX_ADDR];
}PeoInfo;


//// ͨѶ¼ ��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX];  // �����ӽ������˵���Ϣ
//	int sz;  // ��¼��ǰͨѶ¼�� ��Ч��Ϣ�ĸ���
//
//}Contact;

// ͨѶ¼ ��̬�汾
typedef struct Contact
{
	PeoInfo *data;  // data -> ָ��̬����Ŀռ� ���������ϵ�˵���Ϣ 
	int sz;  // ��¼��ǰͨѶ¼�� ��Ч��Ϣ�ĸ���
	int capacity;   // ��¼��ǰͨѶ¼���������

}Contact;

// ��ʼ��ͨѶ¼
void InitContact(Contact* pc);

// ������ϵ��
void AddContact(Contact* pc);

// �鿴
void PrintContact(const Contact* pc);

// ɾ��
void DelContact(Contact* pc);

// ����
void SearchContact(Contact* pc);

// �޸�
void ModifyContact(Contact* pc);

// ����ͨѶ¼
void DestoryContact(Contact* pc);