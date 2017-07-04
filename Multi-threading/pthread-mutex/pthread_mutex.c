/*---------------------------------------------------------------------------
*
* pthread_mutex.c
*
*     07/04/2017 - This is a program which demonstrates usage of mutex in
*     multi-thread programming.
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
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
#define MAX_NUMBER_OF_THREADS 2
uint32_t gCounter = 0;
typedef struct thread_info{
    pthread_t tid;
    uint32_t thNumber;
}thread_info_t;

void pthread_fn (void *args)
{
    int32_t iret = -1;
    thread_info_t *thInfo = (struct thread_info *)args;
    do
    {
        iret = pthread_mutex_trylock(&mutex1);
        if(iret == EBUSY)
        {
            printf("\n[ThreadID:%d][Thread Number:%u] Mutex1 is locked..will retry", thInfo->tid, thInfo->thNumber);
        }

    }while (iret != 0);
    printf("\n[ThreadID:%d][Thread Number:%u] Got Mutex1 lock..gCounter=%u\n", thInfo->tid, thInfo->thNumber, gCounter);
    gCounter = gCounter + 10;
    sleep(5);
    printf("\n[ThreadID:%d][Thread Number:%u] After incrementing..gCounter=%u\n", thInfo->tid, thInfo->thNumber, gCounter);
    pthread_mutex_unlock(&mutex1);

}
int main()
{
    thread_info_t thInfo[MAX_NUMBER_OF_THREADS];
    memset(thInfo, 0, MAX_NUMBER_OF_THREADS);
    int32_t iret = -1;
    uint32_t index = 0;
    for(index=0; index <2; index++)
    {
        thInfo[index].thNumber = index + 1;
        iret = pthread_create(&thInfo[index].tid, NULL, (void *) &pthread_fn, (void *)&thInfo[index]);
        if(iret != 0)
        {
            printf("\n[ThreadNum:%u] pthread_create failed with return code:%d\n", index, iret);
            return -1;
        }
    }
    for(index=0; index < 2; index++)
    {
         iret = pthread_join(thInfo[index].tid, NULL);
         if(iret != 0)
         {
             printf("\n[ThreadID:%d][ThreadNum:%u] pthread_join failed with return code:%d\n", thInfo[index].tid, thInfo[index].thNumber, iret);
             return -1;
         }
    }
    return 0;
}
