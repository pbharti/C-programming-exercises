/*---------------------------------------------------------------------------
*
* pthread.c
*
*     06/30/2017 -
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
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
typedef struct threadInfo {
    pthread_t tid;
    uint32_t taskID;
    char taskName[128];
}thInfo;
#define MAX_WQ_THREADS 8
void workerThread_fn (void *ptr)
{
    thInfo *tInfo = NULL;
    tInfo = (thInfo *)ptr;
    uint32_t counter = tInfo->taskID;
    while(1)
    {
        printf("[Task:%d][Name:%s]----Counter=%d-----\n", tInfo->taskID, tInfo->taskName, counter++);
        sleep(2);
    }
}

int main(int argc , char **argv)
{
    thInfo thArgs[MAX_WQ_THREADS];
    memset(thArgs, 0, sizeof(thArgs));
    uint32_t thCount = 0;
    if(argv[1])
    {
        thCount = atoi(argv[1]);
        if(thCount > 8)
            thCount = 8;
    }
    else
        thCount = 1;
    uint32_t index;
    int32_t ret = -1;
    for(index=0; index<thCount; index++)
    {
        thArgs[index].taskID = index;
        snprintf(thArgs[index].taskName, 128, "%s%d", "Worker", index);
        ret = pthread_create(&thArgs[index].tid, NULL,(void *)&workerThread_fn, (void*) &thArgs[index]);
        if(ret < 0)
        {
            printf("\nFailed to create thread..[Task:%d][Name:%s]...\n", thArgs[index].taskID, thArgs[index].taskName);
            return -1;
        }
    }
    for(index=0; index<thCount; index++)
    {
         ret = pthread_join(thArgs[index].tid, NULL);
         if(ret < 0 )
             printf("\npthread_join failed for [Task:%d][Name:%s]...\n", thArgs[index].taskID, thArgs[index].taskName);
    }
    return 0;

}
