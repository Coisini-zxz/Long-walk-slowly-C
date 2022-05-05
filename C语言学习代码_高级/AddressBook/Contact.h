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




// 类型的定义
typedef struct PeoInfo
{
	char Name[MAX_NAME];
	char Sex[MAX_SEX];
	int Age;
	char Tele[MAX_TELE];
	char Addr[MAX_ADDR];
}PeoInfo;


//// 通讯录 静态版本
//typedef struct Contact
//{
//	PeoInfo data[MAX];  // 存放添加进来的人的信息
//	int sz;  // 记录当前通讯录中 有效信息的个数
//
//}Contact;

// 通讯录 静态版本
typedef struct Contact
{
	PeoInfo *data;  // data -> 指向动态申请的空间 用来存放联系人的信息 
	int sz;  // 记录当前通讯录中 有效信息的个数
	int capacity;   // 记录当前通讯录的最大容量

}Contact;

// 初始化通讯录
void InitContact(Contact* pc);

// 增加联系人
void AddContact(Contact* pc);

// 查看
void PrintContact(const Contact* pc);

// 删除
void DelContact(Contact* pc);

// 查找
void SearchContact(Contact* pc);

// 修改
void ModifyContact(Contact* pc);

// 销毁通讯录
void DestoryContact(Contact* pc);