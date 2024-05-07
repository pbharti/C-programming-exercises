#include <stdio.h>

void dumpArray(int *arr, size_t size) {
    if(arr == NULL || size == 0) {
        return;
    }
    for(int i=0; i<size; i++) {
        printf("%d ",arr[i] );
    }
    printf("\n");
}

void insertionSort(int *arr, size_t size) {
    for(int i=1; i< size; i++) {
        int hole = i;
        while(hole > 0) {
            if (arr[hole] < arr[hole-1]) {
                int temp  = arr[hole];
                arr[hole] = arr[hole-1];
                arr[hole-1] = temp;
                hole--;
            } else {
                break;
            }
        }
    }
}

int main() {
    int input_arr[8] = {2,7,4,3,6,1,5,8};
    size_t size = sizeof(input_arr)/sizeof(int);
    printf("Unsorted imput: ");
    dumpArray(input_arr, size);
    insertionSort(input_arr, size);
    printf("Sorted output: ");
    dumpArray(input_arr, size);
    return 0;
}