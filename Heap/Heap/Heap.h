#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap{
	HPDataType* arr;
	int size;
	int capacity;

}HP;

void HPInit(HP* php);

void HPDestroy(HP* php);

void HPPush(HP* php, HPDataType x);

void HPPrint(HP* php);

void HPPop(HP* php);

bool HPEmpty(HP* php);

HPDataType HPTop(HP* php);

//向下调整算法
void AdjustDown(HP* php, int parent, int n);

//向上调整
void AdjustUp(HPDataType* arr, int child);
