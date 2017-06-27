/*---------------------------------------------------------------------------
*
* parser_main.c
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
#include "parser.h"
gArgs_t global_args;
static const char *optString = "n:c:o:vh?";

void display_usage()
{
    printf("\n######### Command options ########\n");
    printf("# -n: number of inputs\n");
    printf("# -c: input file name\n");
    printf("# -o: output file name\n");
    printf("# -v: verbosity\n");
    printf("# -h: Help\n");
}


int main(int argc, char *argv[])
{
     int opt = 0;
     memset(&global_args, 0, sizeof(global_args));
#if 0
     global_args.count = 0;
     global_args.infile = {"\0"};
     global_args.outfile = {"\0"};
     global_args.verbose_enable = 0;
#endif
     opt = getopt(argc, argv, optString);
     while(opt != -1)
     {
          switch(opt)
          {
              case 'n':
                  printf("\n parsed count option = %d\n",atoi(optarg));
                  global_args.count = atoi(optarg);
                  break;
              case 'c':
                  printf("\n parsed input file = %s\n",optarg);
                  strncpy(global_args.infile, optarg, strlen(optarg));
                  break;
              case 'o':
                  printf("\n parsed output file = %s\n",optarg);
                  strncpy(global_args.outfile, optarg, strlen(optarg));
                  break;
              case 'v':
                  printf("\n parsed verbosity is set\n");
                  global_args.verbose_enable = 1;
                  break;
              case 'h':
              case '?':
                  printf("\n printing help string \n");
                  display_usage();
                  break;
              default:
                  printf("\n Invalid Input\n");
          }
        opt = getopt(argc, argv, optString);
     }
     return 0;
}
