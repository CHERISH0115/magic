#include<stdio.h>
#include<string.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(int arr[], int n) {
	for (int i = 0; i < n; i += 4) {
		if (i + 4 < n) { // ȷ������Խ��
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

	//�����ʼ����
	printf("��ʼ���飺");
	printArr(arr, 8);

	//��һ�����û�
	permutation(arr, 8);
	printf("�û���");
	printArr(arr, 8);

	//�ڶ��������˵��Ʒŵ��׶�
	rotate(arr, 8);
	printf("���˵��Ʒŵ��׶˺�");
	printArr(arr, 8);

	//������������
	insert(arr, 8);
	printf("�����");
	printArr(arr, 8);

	//���Ĳ������ߵ�һ��Ԫ�أ��������һ��Ԫ�أ�
	extract(arr, 8);
	printf("���ߵ�һ��Ԫ�غ�");
	printArr(arr,8);

	//���岽�������ϱ����������м���ǰ���Ԫ��
	shuffle(arr, 8);
	printf("�����ϱ����������ƺ�");
	printArr(arr, 8);



	return 0;
}