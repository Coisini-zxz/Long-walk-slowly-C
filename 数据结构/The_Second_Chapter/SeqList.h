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


int Del_Min(SL* ps);
void reverse(SL* ps);
void Del_x(SL* ps, Elemtype x);
void Del_s_t(SL* ps, Elemtype s, Elemtype t);