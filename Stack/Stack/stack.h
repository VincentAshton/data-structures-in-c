#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack {
	STDataType* arr;
	int top; //指向栈顶的位置,也是有效的数据个数
	int capacity;
}ST;

//初始化
void STInit(ST* phead);

//销毁
void STDestroy(ST* ps);

//入栈
void STPush(ST* ps, STDataType x);

//出栈
void STPop(ST* ps);

//判断栈是否为空
bool STEmpty(ST* ps);

//取栈顶元素
STDataType STTop(ST* ps);