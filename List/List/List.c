#include "List.h"

//申请新结点
LTNode* LTBuyNode(LTDataType x) {
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL) {
		perror("malloc fail.");
		exit(1);
	} 
	newnode->data = x;
	newnode->next = newnode->prev = newnode;
}

//初始化
//void LTInit(LTNode** pphead) {
//	*pphead = LTBuyNode(-1);
//}

LTNode* LTInit() {
	LTNode* phead = LTBuyNode(-1);
	return phead;
}

//尾插
void LTPushBack(LTNode* phead,LTDataType x) {
	assert(phead);
	LTNode* plast = LTBuyNode(x);
	phead->prev->next = plast;
	plast->prev = phead->prev;
	plast->next = phead;
	phead->prev = plast;
}

//头插
void LTPushFront(LTNode* phead, LTDataType x) {
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

//判断节点是否为空
int LTEmpty(LTNode* phead)
{
	assert(phead);
	return (phead->next == phead);
}

//尾删
void LTPopBack(LTNode* phead) {
	assert(!LTEmpty(phead));

	LTNode* del = phead->prev;

	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;

	free(del);
	del = NULL;
}

//打印
void LTPrint(LTNode* phead) {
	LTNode* pcur = phead->next;
	while (pcur != phead) {
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

//头删
void LTPopFront(LTNode* phead) {
	assert(!LTEmpty(phead));

	LTNode* del = phead->next;
	phead->next->next->prev = phead;
	phead->next = phead->next->next;

	free(del);
	del = NULL;
}

//查找
LTNode* LTFind(LTNode* phead, LTDataType x) {
	assert(!LTEmpty(phead));
	assert(phead);

	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x) {
			return pcur;
		}
		pcur = pcur->next;
	}

	return NULL;
}

//pos之后插入
void LTInsert(LTNode* pos, LTDataType x) {
	assert(pos);

	LTNode* newnode =  LTBuyNode(x);
	newnode->next = pos->next;
	pos->next->prev = newnode;
	pos->next = newnode;
	newnode->prev = pos;
}

//删除pos位置节点
void LTErase(LTNode* pos) {
	assert(pos);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

//销毁
//void LTDestroy(LTNode** pphead) {
	//LTNode* pcur = (*pphead)->next;

	//while (pcur!=*pphead) {
	//	LTNode* next = pcur->next;
	//	free(pcur);
	//	pcur = next;
	//}

	//free(*pphead);
	//*pphead = NULL;
//}

void LTDestroy(LTNode* phead) {
	LTNode* pcur = phead->next;

	while (pcur != phead) {
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}

	free(phead);
	phead = NULL;
}