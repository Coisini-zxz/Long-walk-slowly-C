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
	// 存储数据 - 二维数组
	char board[ROW][COL];
	// 初始化棋盘  - 初始化空格
	InitBoard(board, ROW, COL);
	// 打印棋盘 - 本质打印数组内容
	DisplayBoard(board, ROW, COL);
	char ret = 0; // 接收游戏状态
	while (1)
	{
		// 玩家下
		PalyerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		// 判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		// 电脑下
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		meau();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}