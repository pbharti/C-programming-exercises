#include <stdio.h>

void Printdata(int *arr, size_t len) {
    if (arr == NULL || len == 0)
        return;
    for(int i=0;i<len;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Bubblesort(int* arr, size_t len) {
    if (arr == NULL || len == 0)
        return;
    for (int i=0; i<len; i++) {
        for (int j=0; j<len-i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}
int main() {
    int input[6] = {2,7,4,1,5,3};
    size_t len = sizeof(input)/sizeof(int);
    printf("######### Input array: \n");
    Printdata(input, len);
    Bubblesort(input, len);
    printf("####### Sorted Input: \n");
    Printdata(input, len);
    return 0;
}