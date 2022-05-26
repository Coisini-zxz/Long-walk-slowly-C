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

	Del_s_t(&sl, 2, 4);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

int main()
{
	// TestSeqList1();
	// problem1();
	// problem2();
	// problem3();
	problem4();
	return 0;
}