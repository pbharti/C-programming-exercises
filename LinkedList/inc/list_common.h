/*---------------------------------------------------------------------------
*
* list_common.h
*
*     01/30/2017 -
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

#ifndef LIST_COMMON_H
#define LIST_COMMON_H
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef struct sllNode{
    int data;
    struct sllNode *next;
}sllNode_t;

static int get_add_options()
{
    printf("######## Please enter your option for adding:\n");
    printf("#1. For adding node at the begining \n");
    printf("#2. For adding node at the end \n");
    printf("#3. For adding node at the given position \n");
    int option = 0;
    scanf("%d",&option);
    return option;
}

#endif /* LIST_COMMON_H */
