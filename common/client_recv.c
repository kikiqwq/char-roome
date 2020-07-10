/*************************************************************************
	> File Name: client_recv.c
	> Author: 
	> Mail: 
	> Created Time: Fri 10 Jul 2020 06:12:13 PM CST
 ************************************************************************/

#include "head.h"

extern int sockfd;
extern int exit_flag;

void * do_recv(void *arg) {
    struct ChatMsg msg;
    while(1) {
        bzero(&msg, sizeof(msg));
        int ret = recv(sockfd, (void *)&msg, sizeof(msg), 0);
        if (ret != sizeof(msg)) {
            continue;
        }
        if (msg.type & CHAT_WALL) {
            printf(""BLUE"%s"NONE" : %s\n", msg.name, msg.msg);
        } else if (msg.type & CHAT_MSG) {
            printf(""RED"%s"NONE" : %s\n", msg.name, msg.msg);

        }  else if (msg.type & CHAT_SYS) {
            printf(""YELLOW"%s"NONE" : %s\n", msg.name, msg.msg);

        }  else if (msg.type & CHAT_FIN) {
            printf(""L_RED"%s"NONE" : %s\n", msg.name, msg.msg);
            exit_flag = 1;
            exit(1);
        } 

    }
}
