#include "SListNode.h"
#include "SListNode.c"

int test01()
{
	//创建一个链表
	SLTNode* node1 =(SLTNode*) malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//打印链表
	SLTNode* plist = node1;
	//或者 SLTPrint(node1);
	SLTPrint(plist);
}

int test02()
{
	 //创建空链表
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushFront(&plist, 0);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPopFront(&plist);

	SLTNode* pos = SLTFind(plist, 2);
	if (pos == NULL)
	{
		printf("not found.\n");
	}
	else
	{
		printf("found.\n");
	}

	SLTInsertAfter(3, 100);
}

int main()
{
	test01();
	return 0;
}
