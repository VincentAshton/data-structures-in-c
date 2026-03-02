#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QueueNode {
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {
	QueueNode* phead;
	QueueNode* ptail;
}Queue;

//初始化
void QueueInit(Queue* pq);

//入队
void QueuePush(Queue* pq,QDataType x);

// 出队列，队头
void QueuePop(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

//队列有效元素个数
int QueueSize(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);

