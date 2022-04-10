#pragma once
#include <stdio.h>

// 函数的定义
#define ROW 3
#define COL 3
// 我淦不要写 ROW=3!

// 函数的声明
// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);


// 打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);


// 玩家下棋
void PalyerMove(char board[ROW][COL], int row, int col);