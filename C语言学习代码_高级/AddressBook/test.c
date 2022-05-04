/*
通讯录实现
通讯录
1.   通讯录中能够存放1000个人的信息 - 每个人的信息:名字+年龄+性别+电话+地址
2．增加人的信息
3．删除指定人的信息
4．修改指定人的信息
5．查找指定人的信息
6．排序通讯录的信息
*/
#define _CRT_SECURE_NO_WARNINGS	1
#include "Contact.h"

void meau()
{
	printf("*******************************************\n");
	printf("*****     1. Add        2. Del       ******\n");
	printf("*****     3. Search     4. Modify    ******\n");
	printf("*****     5. Sort       6. Print     ******\n");
	printf("*****            0. Exit             ******\n");
	printf("*******************************************\n");

}

enum Opention
{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Sort,
	Print
};

int main()
{
	int input = 0;
	// 创建通讯录
	Contact con;  
	// 初始化通讯录
	InitContact(&con);
	do
	{
		meau();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			AddContact(&con);
			break;
		case Del:
			DelContact(&con);
			break;
		case Search:
			SearchContact(&con);
			break;
		case Modify:
			ModifyContact(&con);
			break;
		case Sort:
			break;
		case Print:
			PrintContact(&con);
			break;
		case Exit:
			printf("退出通讯录!\n");
			break;
		default:
			printf("选择错误! 请重新选择 \n");
			break;
		}
	} while (input);
	return 0;
}