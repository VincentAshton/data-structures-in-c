#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 声明线性表
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

void SLTInit(SL* ps);
void SLDestroy(SL* ps);

//尾插
void SLPushBack(SL* ps,SLDataType x);

//头插
void SLPushFront(SL* ps, SLDataType x);

//尾shan
void SLPopBack(SL* ps);
//头删
void SLPopFront(SL* ps);

//指定位置之前插入数据
void SLInsert(SL* ps, int pos,SLDataType x);
//指定位置之后删除数据
void SLErase(SL* ps, int pos);

