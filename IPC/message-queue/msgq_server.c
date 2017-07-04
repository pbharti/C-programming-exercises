/*---------------------------------------------------------------------------
*
* msgq_server.c
*
*     07/04/2017 - This Program demonstrates a simple usage of
*     message queue for client server communication. This is the
*     server side code.
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
    key_t msg_key;
    int32_t mqid = 0;
    message_t msg;
    memset(&msg, 0, sizeof(msg));
    if((msg_key = ftok(SERVER_KEY_PATHNAME, PROJECT_ID)) == -1)
    {
        perror("ftok");
        return -1;
    }
    if((mqid = msgget(msg_key, IPC_CREAT | QUEUE_PERMISSION)) == -1)
    {
        perror("msgget");
        return -1;
    }
    printf("Server: Server process started....\n");
    while(1)
    {
        /* Read an incoming message from client */
        int32_t rx_len = -1;
        printf("server queue id=%u\n", mqid);
        rx_len = msgrcv(mqid, &msg, 64, 0, MSG_NOERROR);
        if(rx_len == -1)
        {
            perror("msgrcv");
            return -1;
        }
        /* Process the received message */
        printf("Received message from client:[%s]..\n", msg.message_text.buf);
        char tx_buf[64] = {0};
        snprintf(tx_buf, rx_len, "%d", rx_len);
        strncat(msg.message_text.buf, tx_buf, strlen(tx_buf));
        int32_t ret = -1;
        uint32_t client_mqid = msg.message_text.reqid;
        msg.type = 0;
        ret = msgsnd(client_mqid, &msg, 64, 0);
        if(ret == -1)
        {
            perror("msgsend");
            return -1;
        }
    }
}
