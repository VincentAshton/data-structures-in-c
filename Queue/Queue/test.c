#include "Queue.h"

void test01() {
	Queue q;
	QueueInit(&q);

	QueuePush(&q,0);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);

	QueuePop(&q);
}

int main() {
	test01();
	return 0;
}