/*---------------------------------------------------------------------------
*
* parent.c
*
*     06/27/2017 -
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
#include <unistd.h>

int main(int argc, char** argv)
{
     printf("\n[Parent]: Started default program...\n");
     uint32_t cpid=0, ppid=0;
     int32_t exec = -1;
     if(argv[1])
         exec = atoi(argv[1]);
     if(!fork())
     {
         pid_t pid = getpid();
         ppid = getppid();
         int32_t ret = 0;
         printf("\n[Child]: own pid:%u, Parent id:%u ..\n", pid, ppid);
         if(exec == 1)
         {
             ret = execl("./child", "./child", NULL);
            if(ret<0)
            {
                printf("\nexecl failed...\n");
                exit(0);
            }
         }
         else
         {
             while(1)
                 continue;

         }
     }
     else
     {
         pid_t pid = getpid();
         ppid = getppid();
         printf("\n[Parent]: own pid:%u, Parent id:%u ..\n", pid, ppid);
         while(1)
             continue;
     }
     return 0;
}
