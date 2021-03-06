/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时04分38秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
int main(int argc, char **argv) {
    signal(SIGCHLD,SIG_IGN)；
    if(argv != 2) {
        fprintf(stderr,"usage : %s port\n",argv[0]);
        exit(1);
    }
    int port,server_listen;
    port = atoi(argv[1]);
    if((server_listen = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socket");
        exit(1);
    }

    printf("socket creat\n");
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_add.s_addr = INADDR_ANY;

    if(bind(server_listen,(struct sockaddr *) &server,sizeof(server)) < 0){
        perror("bind");
        exit(1);
    }

    printf("socket bind\n");
    if(listen(server_listen, 20) < 0) {
        perror("server");
        exit(1);
    }

    while(1) {
        int sockfd;
    printf("socket before\n");
        if(sockfd = accept(server_listen, NULL, NULL) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }

        pid_t pid;
        if((pid = fork()) < 0) {
            perror("fork");
            continue;
        }
        if(pid == 0) {
            close(server_listen);
            char name[20] = {0};
            if(recv(sockfd,name,sizeof(name), 0) <= 0) {
                perror("recv");
                close(sockfd);
            }
            printf("name = %s\n",name);
            exit(0);
        }

        char name[20] = {0};
        if(recv(sockfd,name, sizeof(name), 0) <= 0) {
            close(sockfd);
            continue;
        }
        printf("%s\n",name);
        close(soockfd);
    }
}
