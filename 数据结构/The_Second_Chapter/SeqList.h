#include <stdio.h>
#include <stdlib.h>

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
void SeqListPushBack(SL* ps, Elemtype x);  // β��
void SeqListPopBack(SL* ps);                       // βɾ
void SeqListPushFront(SL* ps, Elemtype x); // ͷ��
void SeqListPopFront(SL* ps);                      // ͷɾ


