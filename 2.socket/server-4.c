/*************************************************************************
	> File Name: server-4.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 11时42分08秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    signal(SIGCHLD, SIG_IGN);
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port\n", argv[0]);
        exit(1);
    }
    int port, server_listen;
    port = atoi(argv[1]);//字符串转为整形

    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    
    printf("Socket create.\n");
    struct sockaddr_in server;
    server.sin_family = AF_INET;//ipv4
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
        //问大爷要了门牌号
    }
    //等别人连我

    printf("Socket bind.\n");

    if (listen(server_listen, 20) < 0) {
        perror("server");
        exit(1);
    }

    while (1) {
        int sockfd;
        printf("Socket before accept.\n");
        if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }        
        pid_t pid;
        if ((pid = fork()) < 0) {
            perror("fork");
            continue;
        }
        
        printf("Socket after accept.\n");
        if (pid == 0) {
            close(server_listen);//?????到底要不要close(server_listen)??
            char name[20] = {0};
            if (recv(sockfd, name, sizeof(name), 0) <= 0) {
                perror("recv");
                close(sockfd);
            }
            printf("Name = %s\n", name);
            exit(0);
        }
    }
    

    return 0;
}

