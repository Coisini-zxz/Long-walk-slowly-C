#include "SListNode.h"

//  2.3��
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void SListPushBack(SLTNode** pphead, SLDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NULL != newnode)
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopBack(SLTNode** pphead)
{
	// ���ֻ��һ���ڵ� û��ɾ�� ֱ��assert���쳣���ɲ�������
	assert(*pphead != NULL);
	// �����Լ���������
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		(*pphead)->next = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		// ������Ȼ�ȼ� �����߼����岻ͬ
		// while (tail->next  != NULL)   
		while (tail->next) // 
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}

	/*
	������������ʱ���ֵ������һ��ȱ�� 
	 βɾ ��ɾ�����һ���ڵ�ʱ �޷����� �ϸ��ڵ��ڵ��¸��ڵ�ĵ�ַ
	 Ҳ����˵ �������޷��ҵ���һ���ڵ�
	������� 
	(1) �ٶ���һ��ָ�� ������tail ָ��tail��ǰһ�� (����)
	(2) �����ٶ���һ��ָ�� ����while����д tail->next->next  (����)
	*/
	// ��������д �����Ҳ��Բ��Կ��ܰ汾���� ��������д  tail->next->next
	//SLTNode* tail = *pphead;
	//while (tail->next->next) // 
	//{
	//	tail = tail->next;
	//}
	//free(tail->next);
	//tail->next = NULL;


}