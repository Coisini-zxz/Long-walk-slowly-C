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
	while (1)
	{
		// 玩家下
		PalyerMove(board, ROW, COL);

	}


}
int main()
{
	int input = 0;
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

