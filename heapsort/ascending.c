//
// Created by pbharti on 2/28/26.
//

#include <stdio.h>

void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        Heapify(arr, size, largest);
    }
}
void HeapSort(int arr[], int size) {
    // build max heap
    for (int i = size/2 - 1; i >= 0; i--) {
        Heapify(arr, size, i);
    }
    // extract the largest one by one
    for (int i = size-1; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        Heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    PrintArray(arr, size);
    HeapSort(arr, size);
    PrintArray(arr, size);
}