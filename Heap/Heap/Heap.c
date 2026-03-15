#include "Heap.h"

void HPInit(HP* php) {
	assert(php);
	php->arr = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HPDestroy(HP* php) {
    if (php && php->arr) {
        free(php->arr);
    }
    if (php) {
        php->arr = NULL;
        php->capacity = 0;
        php->size = 0;
    }
}

void Swap(HPDataType* x, HPDataType* y) {
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整
void AdjustUp(HPDataType* arr,int child) {
	int parent = (child - 1) / 2;
	while (child) {
		
		if (arr[child] < arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
//向下调整算法
void AdjustDown(HPDataType* arr,int parent,int n) {
	int child = parent * 2 + 1;

	while (child < n) {
		if (child+1<n && arr[child] > arr[child + 1]) {
			child++;
		}

		if (arr[child] < arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x) {
	assert(php);

	//判断是否需要扩容
	if (php->capacity == php->size) {
		int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
        HPDataType* tmp = (HPDataType*)realloc(php->arr, newCapacity * sizeof(HPDataType));
		if (tmp == NULL) {
			perror("realloc fail.");
			exit(1);
		}

		php->arr = tmp;
		php->capacity = newCapacity;
	}
	//空间足够
	php->arr[php->size] = x;

	//向上调整
	AdjustUp(php->arr, php->size);
	++php->size;
}

void HPPrint(HP* php) {
    assert(php->arr); // Ensure php->arr is not NULL
    assert(php);
    for (int i = 0; i < php->size; i++) {
		printf("%d ", php->arr[i]);
    }
	printf("\n");
}


bool HPEmpty(HP* php) {
	assert(php);

	return php->size == 0;
}

//出堆
void HPPop(HP* php) {
    assert(php);
    assert(php->size > 0);

    Swap(&php->arr[0], &php->arr[--php->size]);
    AdjustDown(php, 0, php->size); // 上面 size 已经减一了
}

HPDataType HPTop(HP* php){
    assert(php);
    assert(php->size > 0);
    return php->arr[0];
}

