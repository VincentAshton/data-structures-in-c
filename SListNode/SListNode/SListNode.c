#include "SListNode.h"

void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}

	printf("\n");
}

//申请新结点
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode)
	{
		newnode->data = x;
		return newnode;
	}
	else
	{
		perror("malloc fail.");
		exit(1);
	}
}

//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != NULL)
		{
			pcur = pcur->next;
		}
		pcur->next = SLTBuyNode(x);
	}
}

//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

//尾删
void SLTPopBack(SLTNode** pphead)
{
	//链表不能为空
	assert(pphead && *pphead);

	//链表只有一个节点的情况
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}  

//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//find
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
	}

	return NULL;
}

//指定位置之前插入
void SLTInset(SLTNode** pphead, SLTNode* pos,SLTDataType x)
{
	assert(pphead && pos);

	SLTNode* newnode = SLTBuyNode(x);

	//pos指向头节点
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else {
		//找pos前一个节点
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}

//指定位置之后插入
void SLTInsertAfter(SLTNode* pos, SLTDataType x){
	assert(pos);

	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos && pphead);
	
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else {
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{

			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos) {
	assert(pos && pos->next);//pos之后的节点也不能为空
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}


//销毁链表
void SListDestroy(SLTNode** pphead) {
	assert(pphead);

	SLTNode* pcur = (*pphead);
	while (pcur != NULL)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}


