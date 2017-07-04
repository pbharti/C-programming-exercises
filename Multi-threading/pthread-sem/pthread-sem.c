/*---------------------------------------------------------------------------
*
* pthread-sem.c
*
*     07/04/2017 - This program illustrates usage of semaphore with
*     pthreads. For the time being we are using two threads to print
*      numbers in increasing order in interleaved manner.
*      E.g
*      TID0; count=1
*      TID1: count=2
*      TID0: count=3
*      TID1: count=4
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
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_NUMBER_OF_THREADS 2
uint32_t gCounter = 0;
sem_t sem1;
sem_t sem2;
typedef struct pthread_info {
     pthread_t tid;
     uint32_t thNumber;
}pthread_info_t;

void pthread_fun1(void *ptr)
{
    pthread_info_t *thInfo = (pthread_info_t *)ptr;
    do {
         sem_wait(&sem1);
         printf("[ThreadID:%u][ThreadNum:%u] gCounter=%u\n", thInfo->tid, thInfo->thNumber, gCounter++);
         sleep(1);
         sem_post(&sem2);
    }while (gCounter < 100);

}
void pthread_fun2(void *ptr)
{
    pthread_info_t *thInfo = (pthread_info_t *)ptr;
    do {
         sem_wait(&sem2);
         printf("[ThreadID:%u][ThreadNum:%u] gCounter=%u\n", thInfo->tid, thInfo->thNumber, gCounter++);
         sleep(1);
         sem_post(&sem1);
    }while (gCounter < 100);
}

int main()
{
     pthread_info_t thInfo[2];
     memset(thInfo, 0, sizeof(thInfo));
     sem_init(&sem1, 0, 1);
     sem_init(&sem2, 0, 0);
     thInfo[0].thNumber = 1;
     thInfo[1].thNumber = 2;
     int32_t iret = -1;
    iret = pthread_create(&thInfo[0].tid, NULL, (void *)&pthread_fun1, (void *)&thInfo[0]);
    if(iret !=0) {
         printf("pthread_create failed for thread number 1\n");
         return -1;
    }
    iret = pthread_create(&thInfo[1].tid, NULL, (void *)&pthread_fun2, (void *)&thInfo[1]);
    if(iret != 0) {
        printf("pthread_create failed for thread number 1\n");
        return -1;
    }
    uint32_t index = 0;
    for(index=0; index<2; index++)
    {
         iret = pthread_join(thInfo[index].tid, NULL);
         if (iret != 0)
         {
             printf("pthread_join failed for thread number %u\n", index);
             return -1;
         }
    }
    return 0;
}


