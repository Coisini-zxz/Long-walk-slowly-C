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
	// 如果 没有空间 或者 空间不足 ---> 扩容
	if (ps->Maxsize == ps->length)
	{
		int NewMaxsize = ps->Maxsize == 0 ? 4 : ps->Maxsize * 2;   // (1) 当前容量为0 则下面开辟4个字节 (2)当前不为0 则下面开辟当前空间的二倍
		Elemtype* tmp = (Elemtype*)realloc(ps->a, NewMaxsize * sizeof(Elemtype));  // 空间占满 realloc开辟新空间
		if (tmp == NULL)  // 检查是否开辟成功
		{
			printf("realloc fail\n");
			exit(-1);    //  异常退出 终止了程序
		}
		ps->a = tmp;  // 开辟好的新地址赋给 数组a
		ps->Maxsize = NewMaxsize;  // 更改最大容量
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
	// 考虑是否需要增容
	SeqListCheckSize(ps);
	// 挪动数据
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
	// 解法一 :
	/*
	(1) 用k记录L中不等于x的元素个数 (= 需要保存下来的元素的个数)
	(2) 遍历 将不等于x的元素移动到下标k的位置
	(3) 修改L的长度为k
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

	// 解法二
	/*
	(1) 用k记录L中等于x的元素个数
	(2) 遍历 !!! 边扫描边统计k (要点: 在找到x是只纪录的k 而且是边找边移) !!!  将不等于x的元素前移k个位置
	(3) 修改L的长度为length-k
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
	ps->length -= k;
}


void Del_s_t_order(SL* ps, Elemtype s, Elemtype t)
{
	assert(ps->length != 0 && s < t && ps->a[0]<=s && ps->a[ps->length-1]>=t);
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


void Del_s_t_disorder(SL* ps, Elemtype s, Elemtype t)
{
	assert(ps->length != 0 && s < t);
	int k = 0;
	for (int i = 0; i < ps->length; i++)
	{
		if (ps->a[i] >= s && ps->a[i] <= t)
		{
			k++;
		}
		else
		{
			ps->a[i - k] = ps->a[i];
		}
	}
	ps->length -= k;

}


void Del_same(SL* ps)
{
	int k = 0;
	assert(ps->length > 0);
	for (int i = 1; i < ps->length; i++)
	{
		if (ps->a[i-1] == ps->a[i])
		{
			k++;
		}
		else
		{
			ps->a[i-k] = ps->a[i];
		}
	}
	ps->length -= k;
}


void SameList_merge(SL* ps1, SL* ps2, SL* ps3)
{
	SeqListCheckSize(ps3);
	int i = 0, j = 0, k = 0;
	while (i < ps1->length && j < ps2->length)
	{
		if (ps1->a[i] <= ps2->a[j])
		{
			SeqListCheckSize(ps3);
			ps3->a[k++] = ps1->a[i++];
		}
		else
		{
			SeqListCheckSize(ps3);
			ps3->a[k++] = ps2->a[j++];
		}
	}
	while (i < ps1->length)
	{
		SeqListCheckSize(ps3);
		ps3->a[k++] = ps1->a[i++];
	}
	while (j < ps2->length)
	{
		SeqListCheckSize(ps3);
		ps3->a[k++] = ps2->a[j++];
	}
	ps3->length = k;
}


void volu_m_n(SL* ps, int m ,int n)
{
	assert(m + n == ps->length);
	// 给前m个开辟单独空间盛放原本的前m个
	Elemtype* m_ = NULL;
	m_ = (Elemtype*)malloc(m * sizeof(Elemtype));
	assert(m_);
	for (int i = 0; i < m; i++)
	{
		*(m_ + i) = ps->a[i];
	}

	// 给后n个开辟单独空间盛放原本的后n个
	Elemtype* n_ = NULL;
	n_ = (Elemtype*)malloc(n * sizeof(Elemtype));
	assert(n_);
	for (int i = 0; i < n; i++)
	{
		*(n_ + i) = ps->a[m+i];
	}

	// 写两个for循环 更改原本的ps->a
	for (int i = 0; i < m; i++)
	{
		ps->a[i] = *(n_ + i);
	}
	for (int i = m; i < ps->length; i++)
	{
		ps->a[i] = *(m_ + i - m);
	}
	// 释放内存
	free(m_);
	free(n_);
	m_ = NULL;
	n_ = NULL;
}

void reverse_arr(int arr[], int from, int to)
{
	int temp = 0;
	for (int i = 0; i < (to - from + 1) / 2; i++)
	{
		temp = arr[from + i];
		arr[from + i] = arr[to-i];
		arr[to - i] = temp;
	}
}