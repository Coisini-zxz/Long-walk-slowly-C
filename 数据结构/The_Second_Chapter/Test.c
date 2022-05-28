#include "SeqList.h"

void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPushFront(&sl, 50);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}


void problem1() 
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 0);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 9);
	SeqListPrint(&sl);

	printf("%d", Del_Min(&sl));

	SeqListDestory(&sl);
}


void problem2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	reverse(&sl);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}


void problem3()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	Del_x(&sl, 2);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}


void problem4()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPrint(&sl);

	Del_s_t_order(&sl, 2, 4);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}


void problem5()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 9);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 3);
	SeqListPrint(&sl);

	Del_s_t_disorder(&sl, 2, 4);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}


void problem6()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPrint(&sl);

	Del_same(&sl);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}


void problem7()
{
	SL sl1;
	SeqListInit(&sl1);
	SeqListPushBack(&sl1, 1);
	SeqListPushBack(&sl1, 3);
	SeqListPushBack(&sl1, 5);
	SeqListPushBack(&sl1, 7);
	SeqListPushBack(&sl1, 9);
	SeqListPushBack(&sl1, 11);
	printf("%s", "s1£º");
	SeqListPrint(&sl1);

	SL sl2;
	SeqListInit(&sl2);
	SeqListPushBack(&sl2, 2);
	SeqListPushBack(&sl2, 4);
	SeqListPushBack(&sl2, 6);
	SeqListPushBack(&sl2, 8);
	printf("%s", "s2£º");
	SeqListPrint(&sl2);

	SL sl3;
	SeqListInit(&sl3);
	printf("%s", "s3£º");
	SeqListPrint(&sl3);
	SameList_merge(&sl1,&sl2,&sl3);
	printf("%s", "s3£º");
	SeqListPrint(&sl3);
}


void problem8()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 9);
	SeqListPrint(&sl);

	volu_m_n(&sl, 4,  4);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

void problem10()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
	reverse_arr(arr, 0, 4);
	reverse_arr(arr, 5, 9);
	reverse_arr(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	// TestSeqList1();
	// problem1();
	// problem2();
	// problem3();
	// problem4();
	// problem5();
	// problem6();
	// problem7();
	// problem8();
	// problem9();
	problem10();
	return 0;
}