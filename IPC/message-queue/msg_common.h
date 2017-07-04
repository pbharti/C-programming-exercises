/*---------------------------------------------------------------------------
*
* msg_common.h
*
*     07/04/2017 -
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

#ifndef MSG_COMMON_H
#define MSG_COMMON_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct message_text {
    uint32_t reqid;
    char buf[64];
}message_text_t;

typedef struct message {
    int32_t type;
    message_text_t message_text;
}message_t;
#define SERVER_KEY_PATHNAME "."
#define PROJECT_ID 123
#define QUEUE_PERMISSION 0660

#endif /* MSG_COMMON_H */
