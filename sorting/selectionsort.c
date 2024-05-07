#include<stdio.h>

void SelectionSort(int *arr, int len);
void PrintInput(int *arr, int len);

int main() {
    // Initialize an input integer array for sorting
    int input[8] = {7, 2, 6, 3, 1, 5, 9, 4};
    int size = sizeof(input)/sizeof(int);
    printf("\n########### Input Array[%d]: #####\n", size);
    PrintInput(input, size);
    SelectionSort(input, size);
    printf("\n########### Sorted Array: #####\n");
    PrintInput(input, size);
    
}

void PrintInput(int *arr, int len) {
    for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
}

void SelectionSort(int * arr, int len) {
    int i, j = 0;
    // Consider index 0 is the one with smallest element.
    for (i=0; i<len-1; i++) {
        // This for loop is for finding ith smallest element,
        // meaning the elemnt that needs to be at index i in sorted array.
        int min = i;
        for (j=i+1; j<len; j++) {
            // Make j in the inner loop equal i+1 and from from this till end look for smallest element.
            // If found update min index value.
            if (arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
