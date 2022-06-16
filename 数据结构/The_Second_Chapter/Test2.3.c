#include "SListNode.h"


/*
顺序表的缺陷
1.  空间不足需要增容 而增容 是要付出代价的
2.  避免频繁扩容 一般满了扩两倍 可能就会造成空间浪费
3.  顺序表要求数据从开始位置连续存储 那么 当我们往头部或者中间插入数据时 需要挪动数据 效率较低
而链表的产生 就是针对顺序表的缺陷而设计的
*/

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);

}


int main()
{
	TestSList1();
	return 0;
}