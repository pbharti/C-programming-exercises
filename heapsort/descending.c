#include<stdio.h>
void PrintArray(int arr[], const int len) {
	for(int i=0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Heapify(int arr[], const int size, int index) {
	int small = index;
	int lchild = 2*index+1;
	int rchild = 2*index+2;
	if (lchild < size && arr[lchild] < arr[small]) {
		small = lchild;
	}
	if (rchild < size && arr[rchild] < arr[small]) {
		small = rchild;
	}
	if (small != index) {
		const int temp = arr[small];
		arr[small] = arr[index];
		arr[index] = temp;
		Heapify(arr, size, small);
	}
}

void HeapSort(int arr[], const int size) {
	// Build Min-heap
	for (int i = size/2-1; i >=0; i--) {
		Heapify(arr, size, i);
	}

	// extract elements one by one
	for (int i = size-1; i >0; i--) {
		const int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		Heapify(arr, i, 0);
	}
}
int main() {
	int arr[] = {6,3,5,7,2,1};
	const int len = sizeof(arr)/sizeof(arr[0]);
	PrintArray(arr, len);
	for(int i=0; i < len; i++) {
		HeapSort(arr, len);
	}
	PrintArray(arr, len);
	return 0;
}
