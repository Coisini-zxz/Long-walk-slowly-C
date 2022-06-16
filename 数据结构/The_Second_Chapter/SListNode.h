#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDateType;

typedef struct SListNode
{
	SLDateType data;
	struct SinglyLinkList* next;
}SLTNode;

void SListPrint(SLTNode*  phead);
void SListPushBack(SLTNode** pphead, SLDateType x);
void SListPopBack(SLTNode** pphead);
