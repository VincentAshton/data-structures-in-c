#include "Heap.h"


void test01() {
	HP hp;
	HPInit(&hp);
	HPPush(&hp, 25);
	HPPush(&hp, 15);
	HPPush(&hp, 10);
	HPPush(&hp, 56);
	HPPush(&hp, 70);
	HPPush(&hp, 30);
	HPPrint(&hp);

	while (!HPEmpty(&hp)) {
		HPDataType top = HPTop(&hp);
		printf("%d ", top);
		HPPop(&hp);
	}


    // 不要在堆已经为空时再 pop
    //HPPop(&hp);
    //HPPrint(&hp);

    HPDestroy(&hp);
}

void HPSort(int* arr,int n) {
	HP hp;
	HPInit(&hp);
	for (int i = 0; i < n; i++) {
		HPPush(&hp, arr[i]);
	}

	int i = 0;
	while (!HPEmpty(&hp)) {
		HPDataType top = HPTop(&hp);
		arr[i++] = top;
		HPPop(&hp);
	}

    HPDestroy(&hp);
}

void BubbleSort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//堆排序
void HeapSort(int* arr, int n) {
	////对一个乱序数组建堆，向下调整算法建堆
	//for (int i = (n - 1 - 1)/2; i >= 0; i--) {
	//	AdjustDown(arr, i, n);
	//}


	//向上调整算法建堆
	for (int i = 0; i < n; i++) {
		AdjustUp(arr, i);
	}
  
	int end = n - 1;
	while (end > 0) {
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}
}

//int main() {
//	//test01();
//	int arr[] ={30,56,25,15,70,10};
//	printf("排序之前：\n");
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
//	printf("排序之后：\n");
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

void CreatData() {
	//造数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL) {
		perror("fopen error.");
		exit(1);
	}

	for (int i = 0; i < n; i++) {
		int x = (rand() + i) % 10000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void TopK() {
	int k = 0;
	printf("please input K:");
	scanf("%d", &k);
	
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL) {
		perror("fopen error.");
		exit(1);
	}

	//申请空间大小为k的整型数组
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL) {
		perror("malloc error.");
		exit(2);
	}
	//读取文件中前k个数据并放到数组中
	for (int i = 0; i < k; i++) {
		fscanf(fout, "%d", &minHeap[i]);
	}
	//数组调整建堆--向下调整算法建小堆，找最大的前k个数建小堆
	for (int i = (k-1-1)/2; i >= 0; i--) {
		AdjustDown(minHeap, i, k);
	}
	//遍历剩下的n-k个数，跟堆顶比较
	int data = 0;
	while (fscanf(fout, "%d", &data) != EOF) {
		if (data > minHeap[0]) {
			minHeap[0] = data;
			AdjustDown(minHeap, 0, k);
		}
	}

	//打印堆中数据
	for (int i = 0; i < k; i++) {
		printf("%d ", minHeap[i]);
	}
	fclose(fout);
}

int main() {
	CreatData();
	TopK();
	return 0;
}