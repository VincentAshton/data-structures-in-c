#include "List.c"
#include "List.h"

void test1() {
	LTNode* plist=LTInit();
	LTPushBack(plist,0);
	LTPushBack(plist,1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushBack(plist, 5);
	LTPushBack(plist, 6);
	LTPushFront(plist, 999);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	LTPopFront(plist);;
	LTPrint(plist);
	LTDestroy(plist);
	plist = NULL;
}

int main() {
	test1();
	return 0;
}