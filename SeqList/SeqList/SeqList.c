#include "SeqList.h"

//初始化
void SLTInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity =  0;
}

void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity) // 需要扩容
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;// 所以这样一步要判断是否为0
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType)); // 第二个参数为要扩容的大小，单位为字节，且该值不能为0
		// 返回值是一个地址

		if (tmp == NULL) // 扩容失败就会返回NULL，所以判断一下
		{
			printf("error.\n");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

//尾插
void SLPushBack(SL* ps,SLDataType x)
{
	assert(ps);//等价于assert(ps != NULL)
	//空间不够
	SLCheckCapacity(ps);
	//空间足够
	ps->arr[ps->size++] = x;
	
}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//空间不够就增容
	SLCheckCapacity(ps);
	//空间足够
	//数据整体向后挪动一位
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i - 1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps && ps->size);
	ps->size--;
}

//头删
void SLPopFront(SL* ps)
{
	assert(ps && ps->size);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//查找
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		if (ps->arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}

//指定位置之前插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps && pos >= 0 && pos < ps->size);

	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i++)
	{
		ps->arr[i] = ps->arr[i - 1];
	}

	ps->arr[pos] = x;
	ps->size++;
}

//删除指定位置数据
void SLErase(SL* ps, int pos)
{
	assert(ps && pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}

	if (pos == ps->size - 1)
	{
		SLPopBack(ps);
	}
	ps->size--;
}

//销毁
void SLDestroy(SL* ps)
{
	if (ps->arr != NULL)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}