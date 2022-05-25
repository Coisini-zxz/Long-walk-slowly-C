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
	// 如果 没有空间 或者 空间不足 ---> 扩容
	if (ps->Maxsize == ps->length)
	{
		int NewMaxsize = ps->Maxsize == 0 ? 4 : ps->Maxsize*2;   // (1) 当前容量为0 则下面开辟4个字节 (2)当前不为0 则下面开辟当前空间的二倍
		Elemtype* tmp = (Elemtype*)realloc(ps->a, NewMaxsize * sizeof(Elemtype));  // 空间占满 realloc开辟新空间
		if (tmp == NULL)  // 检查是否开辟成功
		{
			printf("realloc fail\n");
			exit(-1);    //  异常退出 终止了程序
		}
		ps->a = tmp;  // 开辟好的新地址赋给 数组a
		ps->Maxsize = NewMaxsize;  // 更改最大容量
	}
	ps->a[ps->length] = x;
	ps->length++;
}