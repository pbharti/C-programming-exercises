/*---------------------------------------------------------------------------
*
* parser.h
*
*     08/26/2016 -
*
*     <pankajbharti.lfc@gmail.com>
*
*     Copyright (c) 2016 Pankaj Bharti
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

#ifndef PARSER_H
#define PARSER_H
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     int count;                 /* -n option */
     char infile[128];          /* -c option */
     char outfile[128];         /* -o option */
     int verbose_enable;        /* -v option */
}gArgs_t;
#endif /* PARSER_H */
