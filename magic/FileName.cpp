#include<stdio.h>
#include<string.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(int arr[], int n) {
	for (int i = 0; i < n; i += 4) {
		if (i + 4 < n) { // 确保不会越界
			swap(arr + i, arr + i + 4);
		}
	}
}

void rotate(int arr[], int n) {
	int temp = arr[0];
	for (int i = 0; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = temp;
}

void insert(int arr[], int n) {
	int temp[3];
	for (int i = 0; i < 3; i++){
		temp[i] = arr[i];
	}
	for (int i = 0; i < n - 3; i++) {
		arr[i] = arr[i + 3];
	}
	for (int i = 0; i < 3; i++) {
		arr[n - 3 + i] = temp[i];
	}
}

void extract(int arr[], int n) {
	int temp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = temp;
}

void shuffle(int arr[], int n) {
	for (int i = 0; i < 3; i++) {
		insert(arr, n);
		extract(arr, n);
	}
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[8] = {1,2,3,4,1,2,3,4};

	//输出初始数组
	printf("初始数组：");
	printArr(arr, 8);

	//第一步：置换
	permutation(arr, 8);
	printf("置换后：");
	printArr(arr, 8);

	//第二步：顶端的牌放到底端
	rotate(arr, 8);
	printf("顶端的牌放到底端后：");
	printArr(arr, 8);

	//第三步：插入
	insert(arr, 8);
	printf("插入后：");
	printArr(arr, 8);

	//第四步：抽走第一个元素（等于最后一个元素）
	extract(arr, 8);
	printf("抽走第一个元素后：");
	printArr(arr,8);

	//第五步：根据南北方重新往中间塞前面的元素
	shuffle(arr, 8);
	printf("根据南北方重新塞牌后：");
	printArr(arr, 8);



	return 0;
}