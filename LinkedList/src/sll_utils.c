/*---------------------------------------------------------------------------
*
* sll_utils.c
*
*     03/04/2017 -
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

#include "list_common.h"
sllNode_t * sllAddNodeatBegining(sllNode_t * head, int newData)
{
    sllNode_t *temp = (sllNode_t *)calloc(1, sizeof(sllNode_t));
    if(!temp)
    {
        printf("\nFailed to allocate memory for new node..\n");
        return NULL;
    }
    temp->data = newData;
    if(!head)
    {
        printf("\nList is empty..Creating the first node for the list..\n");
        temp->next = NULL;
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}

sllNode_t *sllAddatEnd(sllNode_t *head, int newData)
{
    sllNode_t *temp = (sllNode_t *)calloc(1, sizeof(sllNode_t));
    if(!temp)
    {
        printf("\nFailed to allocate memory for new node...\n");
        return NULL;
    }
    temp->data = newData;
    if(!head)
    {
        temp->next = NULL;
        head = temp;
        return head;
    }
    sllNode_t iter = head;
    while(iter->next != NULL)
        iter = iter->next;
    iter->next = temp;
    return head;
}
