#include "SeqList.h"

void test01()
{
	SL sl;
	SLTInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 0);
	SLPopBack(&sl);
	SLPushBack(&sl, 9);
	SLPopFront(&sl);
	SLInsert(&sl, SLFind(&sl, 2), 100);
	SLErase(&sl, 3);

	SLDestroy(&sl);
}

int main()
{
	test01();
	return 0;
}