#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
// ������Ԫ�����Ͷ���
typedef int Elemtype;

// �������ݽṹ+������
typedef struct SeqList
{
	Elemtype* a;              // ��ָ����ʵ�ֶ�̬
	int Maxsize, length;  // �������������͵�ǰԪ�ظ���
}SL;

// �ӿں���
void SeqListInit(SL* ps);    //  ��ʼ��
void SeqListCheckSize(SL* ps);  // ����Ƿ���Ҫ���ݲ�����
void SeqListPrint(SL* ps);  //  ��ӡ
void SeqListPushBack(SL* ps, Elemtype x);  // β��
void SeqListPopBack(SL* ps);                       // βɾ
void SeqListPushFront(SL* ps, Elemtype x); // ͷ��
void SeqListPopFront(SL* ps);                      // ͷɾ
void SeqListDestory(SL* ps);  // ����

// �ڶ���ϰ��
int Del_Min(SL* ps);
void reverse(SL* ps);
void Del_x(SL* ps, Elemtype x);
void Del_s_t_order(SL* ps, Elemtype s, Elemtype t);
void Del_s_t_disorder(SL* ps, Elemtype s, Elemtype t);
void Del_same(SL* ps);
void SameList_merge(SL* ps1, SL* ps2, SL* ps3);
void volu_m_n(SL* sp, int m , int n);
