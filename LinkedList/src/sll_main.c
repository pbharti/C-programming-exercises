/*---------------------------------------------------------------------------
*
* sll_main.c
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
#include <list_common.h>

sllNode_t *pHead = NULL;

int main()
{
    int option;
    while(1)
    {
        printf("############# Enter your option ########\n");
        printf("#1. Add a node to the linked list      #\n");
        printf("#2. Delete a node from the linked list #\n");
        printf("#3. Traverse a linked list             #\n");
        printf("#4. Quit this application              #\n");
        printf("#5. Create default list                #\n");
        printf("#6. Iterate using two pointers         #\n");
        printf("#SLL>");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                {
                    printf("\n\nAdding a node now\n");
                    printf("Enter node data: ");
                    int data = 0;
                    scanf("%d", &data);
                    pHead = sllAddatBegining(pHead, data);
                    break;
                }
            case 2:
                {
                    int position = 0;
                    printf("\n\nDeleting a node now..Enter the position:\n");
                    scanf("%d", &position);
                    pHead = sllDelete(pHead, position);
                    break;
                }
            case 3:
                {
                    printf("\n\nTraversing a Linked list now\n");
                    sllTraverse(pHead);
                    break;
                }
            case 4:
                {
                    printf("\n\nNothing to be done..quitting now\n");
                    break;
                }
            case 5:
                {
                    printf("\n\nCreating default single linked list\n");
                    pHead = sllCreateDefault(pHead);
                    break;
                }
            case 6:
                {
                    printf("\n\n Iterating using two pointers on a single linked list\n");
                    sllIterateWithTwo(pHead);
                    break;
                }
            default:
                {
                    printf("\n\nInvalid option. Enter your option againa\n");
                    break;
                }
        }
        if(option == 4)
            return 0;
    }
    return 0;
}

