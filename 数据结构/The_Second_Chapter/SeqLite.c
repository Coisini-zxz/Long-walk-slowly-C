#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->Maxsize = ps->length = 0;
}
void SeqListPrint(SL* ps) 
{
	for (int i = 0; i < ps->length; i++)
	{
		printf("%d ", ps->a[i]);
	}
}
void SeqListDestory(SL* ps) 
{
	free(ps->a);
	ps->a = NULL;
	ps->Maxsize = ps->length = 0;
}
void SeqListPushBack(SL* ps, Elemtype x)
{
	// ��� û�пռ� ���� �ռ䲻�� ---> ����
	if (ps->Maxsize == ps->length)
	{
		int NewMaxsize = ps->Maxsize == 0 ? 4 : ps->Maxsize*2;   // (1) ��ǰ����Ϊ0 �����濪��4���ֽ� (2)��ǰ��Ϊ0 �����濪�ٵ�ǰ�ռ�Ķ���
		Elemtype* tmp = (Elemtype*)realloc(ps->a, NewMaxsize * sizeof(Elemtype));  // �ռ�ռ�� realloc�����¿ռ�
		if (tmp == NULL)  // ����Ƿ񿪱ٳɹ�
		{
			printf("realloc fail\n");
			exit(-1);    //  �쳣�˳� ��ֹ�˳���
		}
		ps->a = tmp;  // ���ٺõ��µ�ַ���� ����a
		ps->Maxsize = NewMaxsize;  // �����������
	}
	ps->a[ps->length] = x;
	ps->length++;
}