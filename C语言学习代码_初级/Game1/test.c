#define _CRT_SECURE_NO_WARNINGS	1
#include "game.h"

void meau()
{
	printf("*******************************************\n");
	printf("************ 1. Play Game *****************\n");
	printf("************ 0. Exit      *****************\n");
	printf("*******************************************\n");
	printf("*******************************************\n");
}

void game() 
{
	// �洢���� - ��ά����
	char board[ROW][COL];
	// ��ʼ������  - ��ʼ���ո�
	InitBoard(board, ROW, COL);
	// ��ӡ���� - ���ʴ�ӡ��������
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		// �����
		PalyerMove(board, ROW, COL);

	}


}
int main()
{
	int input = 0;
	do
	{
		meau();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}

