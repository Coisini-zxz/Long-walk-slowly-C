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

// 第二章习题
int Del_Min(SL* ps);
void reverse(SL* ps);
void Del_x(SL* ps, Elemtype x);
void Del_s_t_order(SL* ps, Elemtype s, Elemtype t);
void Del_s_t_disorder(SL* ps, Elemtype s, Elemtype t);
void Del_same(SL* ps);
void SameList_merge(SL* ps1, SL* ps2, SL* ps3);
void volu_m_n(SL* sp, int m , int n);
