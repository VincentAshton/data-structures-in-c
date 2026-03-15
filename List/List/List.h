#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//定义双向链表结构
typedef int LTDataType;
typedef struct ListNode {
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//初始化
//void LTInit(LTNode** phead);
LTNode* LTInit();

//尾插
void LTPushBack(LTNode* phead, LTDataType x);

//头插
void LTPushFront(LTNode* phead, LTDataType x);

//尾删
void LTPopBack(LTNode* phead);

//打印
void LTPrint(LTNode* phead);

//头删
void LTPopFront(LTNode* phead);

//查找
LTNode* LTFind(LTNode* phead, LTDataType x);

//pos之后插入
void LTInsert(LTNode* pos, LTDataType x);

//删除pos位置节点
void LTErase(LTNode* pos);

//销毁
//void LTDestroy(LTNode** pphead);
void LTDestroy(LTNode* phead);