/*
ͨѶ¼ʵ��
ͨѶ¼
1.   ͨѶ¼���ܹ����1000���˵���Ϣ - ÿ���˵���Ϣ:����+����+�Ա�+�绰+��ַ
2�������˵���Ϣ
3��ɾ��ָ���˵���Ϣ
4���޸�ָ���˵���Ϣ
5������ָ���˵���Ϣ
6������ͨѶ¼����Ϣ
*/

// 1000���˿��ٵĿռ�̫���˷� 
/*
�汾�� 
��̬�����İ汾
1. ͨѶ¼��ʼ���� ���Ǵ��2���˵���Ϣ
2. ���洢�ռ���ʱ ����2���˵���Ϣ
---> 3+2+2+......

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
	// ����ͨѶ¼
	Contact con;  
	// ��ʼ��ͨѶ¼
	// ��data����һ�������Ŀռ��ڶ�����
	// sz = 0  capacity��ʼ��Ϊ��ǰ��������
	InitContact(&con);
	do
	{
		meau();
		printf("��ѡ��:> ");
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
			// ����ͨѶ¼
			DestoryContact(&con);
			printf("�˳�ͨѶ¼!\n");
			break;
		default:
			printf("ѡ�����! ������ѡ�� \n");
			break;
		}
	} while (input);
	return 0;
}