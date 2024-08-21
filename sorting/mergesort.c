#include<stdio.h>
#include<stdlib.h>
void DumpArray(int *input, size_t len) {
    if(!len || input == NULL) {
        return;
    }
    for(int i=0; i < len; i++) {
        printf("%d, ", input[i]);
    }
    printf("\n");
}
void Merge(int *left, int *right, size_t lenl, size_t lenr, int *output) {
    int i=0, j=0, k=0;
    while(i<lenl && j<lenr)  {
        if(left[i] < right[j]) {
            output[k] = left[i];
            i++;
        } else {
            output[k] = right[j];
            j++;
        }
        k++;
    }
    if (i < lenl) {
        while(i<lenl) {
            output[k] = left[i];
            i++;
            k++;
        }
    }
    if (j < lenr) {
        while(j<lenr) {
            output[k] = right[j];
            j++;
            k++;
        }
    }
}
void MergeSort(int *arr, size_t len) {
    if(!len || len <2) {
        return;
    }
    int mid = len/2;
    int left[mid];
    int right[len-mid];

    for (int i=0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i=mid; i < len; i++) {
        right[i-mid] = arr[i];
    }
    MergeSort(left, mid);
    MergeSort(right, len-mid);
    Merge(left, right, mid, len-mid, arr);
    return;
}

int main() {
    int input[9] = {2,4,1,6,8,5,9,3,7};
    size_t len = sizeof(input)/sizeof(int);
    printf("Unsorted array: ");
    DumpArray(input, len);
    MergeSort(input, len);
    printf("Sorted Array: ");
    DumpArray(input, len);
    return 0;
}
