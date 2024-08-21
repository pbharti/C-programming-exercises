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

sllNode_t * sllAddatBegining(sllNode_t * head, int newData)
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

sllNode_t *sllCreateDefault(sllNode_t *head) {
    head = sllAddatEnd(head, 1);
    head = sllAddatEnd(head, 3);
    head = sllAddatEnd(head, 9);
    head = sllAddatEnd(head, 5);
    head = sllAddatEnd(head, 7);
    head = sllAddatEnd(head, 2);
    head = sllAddatEnd(head, 4);
    head = sllAddatEnd(head, 6);
    head = sllAddatEnd(head, 8);
    head = sllAddatEnd(head, 10);
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
    sllNode_t *iter = head;
    while(iter->next != NULL)
        iter = iter->next;
    iter->next = temp;
    return head;
}

sllNode_t *sllAdd(sllNode_t *head, int newData, int pos)
{
    sllNode_t *new = NULL;
    new = (sllNode_t *)malloc(sizeof(sllNode_t));
    new->data = newData;
    new->next = NULL;

    if(!head)
    {
        printf("\nSLL is empty..Adding at the head itself\n");
        head = new;
        return head;
    }
    /* SLL is not empty. Traverse to correct position to add */
    sllNode_t *ptr = head;
    uint32_t loc = 0;
    while((loc < pos) || (ptr != NULL))
    {
        ptr = ptr->next;
        loc++;
    }
    if(!ptr)
    {
        printf("\n Reached %d node.. Adding new node at %d position..\n", loc, loc+1);
        sllNode_t *temp = ptr->next;
        ptr->next = new;
        new->next = temp;
    }
    if(!ptr)
    {
        if(loc < pos)
            printf("\n Can not add node at %dposition..List has only %d elements..\n", pos, loc);
        return head;
    }
    return head;
}

void sllTraverse(sllNode_t *head) {
    sllNode_t *iter = head;
    printf("Single Linked List Data: ");
    while(iter != NULL) {
        if(iter->next != NULL)
            printf("[%p]%d-->", iter, iter->data);
        else
            printf("[%p]%d", iter, iter->data);
        iter = iter->next;
    }
    printf("\n\n");
}

sllNode_t * sllDelete(sllNode_t *head, int position) {
    if (!head)
        return NULL;
    sllNode_t *temp = head;
    if(position <= 1) {
        printf("Removing Linked List node from begining since position specified is : %d\n", position);
        head = head->next;
        free(temp);
        return head;
    }
    int iter = 1;
    while((iter < position-1) && (temp != NULL)){
        iter ++;
        temp = temp->next;
    }
    sllNode_t * temp2 = temp->next;
    printf("Removing Linked List node at position: %d and data: %d\n", position, temp2->data);   
    temp->next = temp2->next;
    free(temp2);
    return head;
}

void sllIterateWithTwo(sllNode_t * head) {
    if(!head)
        return;
    sllNode_t *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("Slow pointer is at: %p/%d\n", slow, slow->data);
    printf("Fast pinter is at %p/%d", fast, fast != NULL?fast->data:0);
}

void sllReverse(sllNode_t *head, sllNode_t *newhead) {
    while()
}
