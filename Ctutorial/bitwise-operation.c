/*---------------------------------------------------------------------------
*
* bitwise-operation.c
*
*     02/20/2017 -
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
#include <stdint.h>
#include <strings.h>
#include <stdlib.h>

int main()
{
    int options = 0;
    int result = -1;
    printf("Enter options for this bit manipulation program\n");
    printf("Enter:\n");
    printf("\t\t1. Given a set of numbers where all elements occur even number of times except one number, \n");
    printf("\t\t   find the odd occuring number.\n");
    printf("\t\t2. Swap two numbers without using temporary variable..\n");
    scanf("%d",&options);
    switch(options)
    {
        case 1:
            {
                int arr[11] = {4,4,1,3,1,3,1,1,3,3,3};
                result = FindOddOccuring(arr, sizeof(arr)/sizeof(int));
                printf("%d occurs odd number of times\n", result);
                break;
            }
        case 2:
            {
                int a1=0, a2=0;
                printf("Enter two numbers for swapping\n");
                scanf("%d %d", &a1, &a2);
                printf("Two numbers before swapping: a1=%d and a2=%d\n", a1, a2);
                result = SwapWithoutTemp(&a1, &a2);
                printf("Two numbers after swapping: a1=%d and a2=%d\n", a1, a2);
                break;
            }
        default:
            printf("Invalid option...\n");
            break;
    }
    return 0;
}

/**
 * @brief A function to find from a given set of numbers,
 * where all elements occur even number of times except one number and
 * finding that number which occurs odd number of times.
 * @param IN int *arr: Input Array
 * @param IN int size: Size of array
 * @paramm OUT NONE.
 * @return int result
 */
int FindOddOccuring (int *arr, int size)
{
    int result;
    int index = 0;
    if(!size)
    {
        printf("Invalid size of array \n");
        return -1;
    }
    for(index=0; index < size; index++)
    {
        result = result ^ arr[index];
    }
    return result;
}

/**
 * @brief A function to swap two variables without using any temporary variable.
 * @param IN int *a1: Address of First number
 * @param IN int *a2: Address of Second Number
 * @paramm OUT 0 or 1 for success and failure case.
 */
int SwapWithoutTemp(int *a1, int *a2)
{
     *a1 = *a1^*a2;
     *a2 = *a1^*a2;
     *a1 = *a1^*a2;
     return 0;
}
