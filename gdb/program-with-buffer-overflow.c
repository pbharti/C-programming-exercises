/*---------------------------------------------------------------------------
*
* program-with-buffer-overflow.c
*
*     07/04/2017 - This program is a classic case of buffer
*     overflow leading to crash and potential corruption of stack frame
*     in the core file. we will try to build/trace the stack in this
*     case.
*     For details analysis follwo the README section.
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

void bar(char* str) {
    char buf[4];
    strncpy( buf, str, 4 );
}

void foo() {
    printf("Hello from foo!");
}

int main(void) {
    bar("This string definitely is too long, sorry!");
    foo();
    return 0;
}
