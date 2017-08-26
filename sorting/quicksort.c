/*---------------------------------------------------------------------------
*
* quicksort.c
*
*     03/06/2017 -
*
*     <pankajbharti.lfc@gmail.com>
*
*     Copyright (c) 2017 Pankaj Bharti
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*     All rights reserved.
*
*---------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void printArray(int *arr, int size)
{
    int index = 0;
    for(index = 0; index < size; index ++)
    {
        printf("%d ", arr[index]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
uint32_t getPartitionIndex(int *arr, int start, int end)
{
    int i = 0,pivot = 0,j = 0;
    pivot = arr[end];
    int pIndex = start;
    for(i=start; i < end; i++ )
    {
        if(arr[i] <= pivot)
        {
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[pIndex], &arr[end]);
    return pIndex;
}

void Qsort(int *arr, int start, int end)
{
    int pIndex = 0;
    if(start < end)
    {
        pIndex = getPartitionIndex(arr, start, end);
        Qsort(arr, start, pIndex-1);
        Qsort(arr, pIndex+1, end);
    }
}
int main()
{
    int arr[9] = {21,2,5,11,9,7,30,1,4};
    printArray(arr, 9);
    uint32_t pivot, pivotIndex, start, end;
    start = 0;
    end = sizeof(arr)/sizeof(int) - 1;
    Qsort(arr, start, end);
    printArray(arr, 9);
    return 0;
}
