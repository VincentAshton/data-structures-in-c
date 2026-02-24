#include "stack.h"

void STInit(ST* ps) {
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}

//销毁
void STDestroy(ST* ps) {
	if (ps->arr) {
		free(ps->arr);
	}
	ps->capacity = 0;
	ps->top = 0;
	ps->arr = NULL;
}

//入栈
void STPush(ST* ps, STDataType x) {
	assert(ps);
	if (ps->capacity == ps->top)
	{
		//malloc
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp = (STDataType*)realloc(ps->arr, newCapacity * sizeof(STDataType));
		if (tmp == NULL) {
			perror("realloc fail.");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}

	ps->arr[ps->top++] = x;
}

//判断栈是否为空
bool STEmpty(ST* ps) {
	assert(ps);

	return ps->top == 0;
}

//出栈
void STPop(ST* ps) {
	assert(!STEmpty(ps));
	ps->top--;
}

//取栈顶元素
STDataType STTop(ST* ps) {
	assert(!STEmpty(ps));

	return ps->arr[ps->top - 1];
}

//获取栈中有效元素个数
int STSize(ST* ps) {
	assert(ps);
	return ps->top;
}

