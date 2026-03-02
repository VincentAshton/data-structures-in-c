#include "Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
}

//入队
void QueuePush(Queue* pq,QDataType x) {
	assert(pq);
	//创建节点
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL) {
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->phead == NULL) {
		pq->phead = pq->ptail = newnode;
	}
	else {  // 队列非空时才执行节点链接
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
}


//判断队列是否为空
bool QueueEmpty(Queue* pq) {
	assert(pq);

	return pq->phead == NULL;
}


// 出队列，队头
void QueuePop(Queue* pq) {
	assert(!QueueEmpty(pq));

	//若队列中只有一个节点
	if (pq->phead == pq->ptail) {
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else {
		//某个节点出队后，要将该节点销毁，因此要提前保存头节点的下一个节点
		QueueNode* nextnode = pq->phead->next;
		free(pq->phead);
		pq->phead = nextnode;
	}
}

//取队头数据
QDataType QueueFront(Queue* pq) {
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}

//取队尾数据
QDataType QueueBack(Queue* pq) {
	assert(!QueueEmpty(pq));

	return pq->ptail->data;
}

//队列有效元素个数
int QueueSize(Queue* pq) {
	assert(pq);
	
	QueueNode* pcur = pq->phead;
	int size = 0;
	while (pcur) {
		++size;
		pcur = pcur->next;
	}

	return size;
}

//销毁队列
void QueueDestroy(Queue* pq) {
	assert(pq);

	QueueNode* pcur = pq->phead;
	while (pcur) {
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}

	pq->phead = pq->ptail = NULL;
}