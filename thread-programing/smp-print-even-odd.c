/*---------------------------------------------------------------------------
*
* smp-print-even-odd.c
*
*     03/05/2017 -
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
#include <string.h>
#include <pthread.h>

typedef struct {
    pthread_t tid;                      /* pthread id */
    uint32_t tnum;                      /* user defined thread number */
    uint32_t stackSize;                 /* Stack size for each thread */
}tinfo_t;

typedef struct {
    uint32_t thread;
    uint32_t counter;
    sem_t *sem;
}targs_t;

void helperThread(targs_t *thinfo)
{
    int count = thinfo->counter;
    while(count < 100)
    {
        printf("\n Thread# %d :counter = %d\n",thinfo->thread, thinfo->counter++);
        count ++;

    }
}
int main(int argc, char **argv)
{
    if(!argc)
    {
        printf("\n Enter a non zero value for number of threads\n");
        return -1;
    }
    int num = atoi(*argv[1]);
    sem_t sem[num-1];
    tinfo_t task[num];
    targs_t thargs[num];
    uint32_t index = 0;
    int rc =0;
    memset(task, 0, sizeof(task));
    memset(thargs, 0, sizeof(thargs));
    for(index = 0; index<num; index++)
    {
        task[index].tnum = index;
        thargs[index].thread = index;
        thargs[index].counter = index;
        sem_init(&sem[indeex], 0, 1);
        thargs[index]->sem = &sem[index];
        rc = pthread_create(&task[index].tid, NULL, (void *) &helperThread, (void *)&thargs[index]);
        if(rc != 0)
        {
            printf("\n Thread creation failed ..\n");
            return -1;
        }
    }
    for(index=0; index<num; index ++)
    {
        rc = pthread_join(task[index].tid, NULL);
        if(rc != 0)
        {
            printf("\n pthread join failed \n");
            return;
        }
    }
    return 0;
}
