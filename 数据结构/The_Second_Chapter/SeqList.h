#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
// 数组内元素类型定义
typedef int Elemtype;

// 定义数据结构+重命名
typedef struct SeqList
{
	Elemtype* a;              // 用指针来实现动态
	int Maxsize, length;  // 数组的最大容量和当前元素个数
}SL;

// 接口函数
void SeqListInit(SL* ps);    //  初始化
void SeqListCheckSize(SL* ps);  // 检查是否需要增容并增容
void SeqListPrint(SL* ps);  //  打印
void SeqListPushBack(SL* ps, Elemtype x);  // 尾插
void SeqListPopBack(SL* ps);                       // 尾删
void SeqListPushFront(SL* ps, Elemtype x); // 头插
void SeqListPopFront(SL* ps);                      // 头删
void SeqListDestory(SL* ps);  // 销毁


int Del_Min(SL* ps);
void reverse(SL* ps);
void Del_x(SL* ps, Elemtype x);
void Del_s_t(SL* ps, Elemtype s, Elemtype t);