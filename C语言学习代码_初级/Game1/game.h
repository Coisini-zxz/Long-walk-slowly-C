#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// �����Ķ���
#define ROW 3
#define COL 3
// ���Ʋ�Ҫд ROW=3!

// ����������
// ��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);


// ��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);


// �������
void PalyerMove(char board[ROW][COL], int row, int col);


// ��������
void ComputerMove(char board[ROW][COL], int row, int col);

// �ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col);

// �ж������Ƿ�����
int IsFull(char board[ROW][COL], int row, int col);