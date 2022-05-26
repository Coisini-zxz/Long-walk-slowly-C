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
	printf("\n");
}


void SeqListDestory(SL* ps) 
{
	free(ps->a);
	ps->a = NULL;
	ps->Maxsize = ps->length = 0;
}

void SeqListCheckSize(SL* ps)
{
	// ��� û�пռ� ���� �ռ䲻�� ---> ����
	if (ps->Maxsize == ps->length)
	{
		int NewMaxsize = ps->Maxsize == 0 ? 4 : ps->Maxsize * 2;   // (1) ��ǰ����Ϊ0 �����濪��4���ֽ� (2)��ǰ��Ϊ0 �����濪�ٵ�ǰ�ռ�Ķ���
		Elemtype* tmp = (Elemtype*)realloc(ps->a, NewMaxsize * sizeof(Elemtype));  // �ռ�ռ�� realloc�����¿ռ�
		if (tmp == NULL)  // ����Ƿ񿪱ٳɹ�
		{
			printf("realloc fail\n");
			exit(-1);    //  �쳣�˳� ��ֹ�˳���
		}
		ps->a = tmp;  // ���ٺõ��µ�ַ���� ����a
		ps->Maxsize = NewMaxsize;  // �����������
	}
}
void SeqListPushBack(SL* ps, Elemtype x)
{
	SeqListCheckSize(ps);
	ps->a[ps->length] = x;
	ps->length++;
}


void SeqListPopBack(SL* ps)
{
	//if (ps->length > 0)
	//{
	//	ps->length--;
	//}
	assert(ps->length > 0);
	ps->length--;

}

void SeqListPushFront(SL* ps, Elemtype x)
{
	// �����Ƿ���Ҫ����
	SeqListCheckSize(ps);
	// Ų������
	int end = ps->length - 1;
	while (end>=0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->length++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps->length > 0);
	int begin = 1;
	while (begin<ps->length)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->length--;
}

int Del_Min(SL* ps)
{
	int min = 0;
	assert(ps->length !=0);
	int value = ps->a[0];
	int pos = 1;
	for (int i =1; i<ps->length;i++)
	{
		if (ps->a[i]<value)
		{
			value = ps->a[i];
			pos = i;
		}
	}
	ps->a[pos] = ps->a[ps->length - 1];
	ps->length--;

	return value;
}


void reverse(SL*ps)
{
	Elemtype temp  = 1;
	for (int i = 0; i < ps->length/2; i++)
	{
		temp = ps->a[i];
		ps->a[i] = ps->a[ps->length - 1 - i];
		ps->a[ps->length - 1 - i] = temp;
	}

}


void Del_x(SL* ps, Elemtype x)
{
	// �ⷨһ :
	/*
	(1) ��k��¼L�в�����x��Ԫ�ظ��� (= ��Ҫ����������Ԫ�صĸ���)
	(2) ���� ��������x��Ԫ���ƶ����±�k��λ��
	(3) �޸�L�ĳ���Ϊk
	*/
	//int k = 0;
	//for (int i = 0; i < ps->length; i++)
	//{
	//	if (ps->a[i] != x)
	//	{
	//		ps->a[k] = ps->a[i];
	//		k++;
	//	}
	//}
	//ps->length = k;

	// �ⷨ��
	/*
	(1) ��k��¼L�е���x��Ԫ�ظ���
	(2) ���� !!! ��ɨ���ͳ��k (Ҫ��: ���ҵ�x��ֻ��¼��k �����Ǳ��ұ���) !!!  ��������x��Ԫ��ǰ��k��λ��
	(3) �޸�L�ĳ���Ϊlength-k
	*/
	int k = 0;
	for (int i = 0; i < ps->length; i++)
	{
		if (ps->a[i] == x)
		{
			k++;
		}
		else
		{
			ps->a[i - k] = ps->a[i];
		}
	}
	ps->length = ps->length -k;
}


void Del_s_t(SL* ps, Elemtype s, Elemtype t)
{
	// assert(ps->length != 0 & s < t & ps->a[0]>=s & ps->a[ps->length-1]>=t);
	int s_ = 0;
	int t_ = 0;
	int z = 0;
	int k = 0;
	for (int i = 0; i < ps->length; i++)
	{
		if (ps->a[i] == s)
		{
			s_ = i;
		}
		if (ps->a[i] ==t)
		{
			t_ = i;
		}
	}
	z = t_ - s_ + 1;
	k = z;
	for (z;z>0;z--)
	{
		ps->a[s_] = ps->a[t_ + 1];
		s_++;
		t_++;
	}
	ps->length = ps->length - k;
}