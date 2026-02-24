#include "stack.c"

void test()
{
	ST st;
	STInit(&st);

	STPush(&st, 0);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);
	printf("%d\n", STSize(&st));

	STpop(&st);

	while (!STEmpty(&st)) {
		STDataType top = STTop(&st);
		printf("%d ", top);
		STPop(&st);
	}


	STDestroy(&st);
}

int main() {
	test();
	return 0;
}