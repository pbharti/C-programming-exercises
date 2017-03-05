/*---------------------------------------------------------------------------
*
* post-pre-operator.c
*
*     02/26/2017 -
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
#include <stdlib.h>

int main()
{
    int arr[] = {10,20};
    int *p = arr;
    *p++;
    printf("\nafter *p++: arr[0]=%d arr[1]=%d *p=%d\n", arr[0], arr[1], *p);
    p = arr;
    *++p;
    printf("\nafter *++p: arr[0]=%d arr[1]=%d *p=%d\n", arr[0], arr[1], *p);
    p = arr;
    ++*p;
    printf("\nafter ++*p: arr[0]=%d arr[1]=%d *p=%d\n", arr[0], arr[1], *p);
    return 0;

}
