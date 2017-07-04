/*---------------------------------------------------------------------------
*
* pthread_cond.c
*
*     07/04/2017 - This program demonstrates usage of condition variable
*     and mutex to run threads in a given sequnece such that thread 1
*     prints only odd number while thread 2 prints only even numbers.
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
#include <errno.h>
#include <pthread.h>

#define MAX_NUMBER_OF_THREADS 2
typedef struct tphread_info {
     pthread_t tid;
     uint32_t thNumber;
}pthread_info_t;
uint32_t gCounter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;

void pthread_fn1 (void *args)
{
    pthread_info_t *thInfo = (pthread_info_t *)args;
    sleep(1);
    do {
        pthread_mutex_lock(&mutex1);
        printf("[Thread ID:%u][ThreadNum:%u] gCounter=%u\n", thInfo->tid, thInfo->thNumber, gCounter++);
        pthread_cond_signal(&cond1);
        pthread_mutex_unlock(&mutex1);

        pthread_mutex_lock(&mutex2);
        pthread_cond_wait(&cond2, &mutex2);
        pthread_mutex_unlock(&mutex2);
    }while (gCounter < 100);
}

void pthread_fn2 (void *args)
{
     pthread_info_t *thInfo = (pthread_info_t *)args;
     do {
         pthread_mutex_lock(&mutex1);
         pthread_cond_wait(&cond1, &mutex1);
         printf("[ThreadID:%u][ThreadNum:%u] gCounter=%u\n", thInfo->tid, thInfo->thNumber, gCounter++);
         pthread_mutex_unlock(&mutex1);

         pthread_mutex_lock(&mutex2);
         pthread_cond_signal(&cond2);
         pthread_mutex_unlock(&mutex2);
     }while (gCounter <100);
}

int main()
{
    pthread_info_t thInfo[2];
    memset(thInfo, 0, sizeof(thInfo));
    int32_t iret = -1;
    thInfo[0].thNumber = 1;
    thInfo[1].thNumber = 2;
    iret = pthread_create(&thInfo[0].tid, NULL, (void *)&pthread_fn1, (void *)&thInfo[0]);
    if(iret != 0) {
        printf("Failed to create thread number 1\n");
        return -1;
    }
    iret = pthread_create(&thInfo[1].tid, NULL, (void *)&pthread_fn2, (void *)&thInfo[1]);
    if(iret != 0) {
        printf("Failed to create thread number 2\n");
        return -1;
    }
    iret = pthread_join(thInfo[0].tid, NULL);
    if(iret != 0) {
         printf("pthread_join failed for thread number 1\n");
         return -1;
    }
    iret = pthread_join(thInfo[1].tid, NULL);
    if(iret != 0) {
         printf("pthread_join failed for thread number 2\n");
         return -1;
    }
    return 0;
}


