#include "SListNode.h"


/*
˳����ȱ��
1.  �ռ䲻����Ҫ���� ������ ��Ҫ�������۵�
2.  ����Ƶ������ һ������������ ���ܾͻ���ɿռ��˷�
3.  ˳���Ҫ�����ݴӿ�ʼλ�������洢 ��ô ��������ͷ�������м��������ʱ ��ҪŲ������ Ч�ʽϵ�
������Ĳ��� �������˳����ȱ�ݶ���Ƶ�
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