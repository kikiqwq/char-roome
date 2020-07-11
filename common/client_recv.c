/*************************************************************************
	> File Name: client_recv.c
	> Author: 
	> Mail: 
	> Created Time: Fri 10 Jul 2020 06:12:13 PM CST
 ************************************************************************/

#include "head.h"

extern int sockfd;
extern WINDOW * message_win, *message_sub, *info_win, *info_sub, *input_win, *input_sub;

void * do_recv(void *arg) {
    struct ChatMsg msg;
    while(1) {
        bzero(&msg, sizeof(msg));
        int ret = recv(sockfd, (void *)&msg, sizeof(msg), 0);
        if (ret != sizeof(msg)) {
            continue;
        }
        if (msg.type & CHAT_WALL) {
            show_message(message_sub, &msg, 0);
        } else if (msg.type & CHAT_MSG) {
            show_message(message_sub, &msg, 0);

        }  else if (msg.type & CHAT_SYS || msg.type & CHAT_FUNC) {
            show_message(message_sub, &msg, 1);

        }  else if (msg.type & CHAT_FIN) {
            show_message(message_sub, &msg, 1);
            exit(1);
        } 

    }
}
