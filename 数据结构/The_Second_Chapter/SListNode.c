#include "SListNode.h"

//  2.3节
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
	// 如果只有一个节点 没法删除 直接assert报异常不可操作即可
	assert(*pphead != NULL);
	// 两个以及两个以上
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		(*pphead)->next = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		// 二者虽然等价 但是逻辑意义不同
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
	在设计这个函数时发现单链表的一个缺点 
	 尾删 在删除最后一个节点时 无法重置 上个节点内的下个节点的地址
	 也就是说 单链表无法找到上一个节点
	解决方法 
	(1) 再定义一个指针 来跟随tail 指向tail的前一个 (上面)
	(2) 不用再定义一个指针 而是while条件写 tail->next->next  (下面)
	*/
	// 课上这样写 但是我测试不对可能版本问题 不能这样写  tail->next->next
	//SLTNode* tail = *pphead;
	//while (tail->next->next) // 
	//{
	//	tail = tail->next;
	//}
	//free(tail->next);
	//tail->next = NULL;


}