/*---------------------------------------------------------------------------
*
* msgq_client.c
*
*     07/04/2017 - This is a sample program to illustrate use of
*     message queue IPC. This is the client side code.
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

#include "msg_common.h"

int main()
{
    message_t msg, rx_msg;
    memset(&msg, 0, sizeof(msg));
    memset(&rx_msg, 0, sizeof(rx_msg));
    key_t msg_key;
    msg_key = ftok(SERVER_KEY_PATHNAME, PROJECT_ID);
    if(msg_key == -1)
    {
        perror("ftok");
        return -1;
    }
    int32_t myqid, server_qid;
    myqid = msgget(IPC_PRIVATE, QUEUE_PERMISSION);
    if(myqid == -1)
    {
        perror("msgget");
        return -1;
    }
    server_qid = msgget(msg_key, 0);
    if(server_qid == -1)
    {
        perror("msgget");
        return -1;
    }
    while(1)
    {
        /* Send message to client */
        printf("Enter the message that needs to be sent to the server..\n");
        char tx_buf[64] = {0};
        fgets(tx_buf, 64, stdin);
        msg.message_text.reqid = myqid;
        snprintf(msg.message_text.buf, 64, "%s", tx_buf);
        msg.type = 0;
        int32_t ret = -1;
        ret = msgsnd(server_qid, &msg, 64, 0);
        if(ret == -1)
        {
            perror("msgsend");
            return -1;
        }
        printf("send message to server with quid=%u\n", server_qid);
        int32_t rx_len = -1;
        rx_len = msgrcv(myqid, &rx_msg, 64, 0, MSG_NOERROR);
        if(rx_len == -1)
        {
            perror("msgrcv");
            return -1;
        }
        printf("Received message from server for client id=%u :[%s]\n", myqid, rx_msg.message_text.buf);
    }
    return 0;
}

