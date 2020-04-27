/*************************************************************************
	> File Name: server-5.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 11时58分34秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
int final;

void *func(void *arg) {
    int sockfd = *(int *)arg;
    
    char name[20] = {0};
    if ((recv(sockfd, name, sizeof(name), 0)) <= 0) {
        perror("recv");
        close(sockfd);
         pthread_exit((void *)&final);
    }
    printf("name = %s\n", name);
    pthread_exit((void*)&final);
    return NULL;
}


int main(int argc, char *argv[]) {
        if (argc != 2) {
        fprintf(stderr, "Usage : %s port \n", argv[0]);
        exit(1);
    }

    int port, server_listen;
    port = atoi(argv[1]);

    if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    printf("Socket create.\n");
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(1);
    }


    printf("Socket bind.\n");

    if (listen(server_listen, 20) < 0) {
        perror("server");
        exit(1);
    }

    while (1) {
        printf("Socket before accept.\n");
        int sockfd;
        if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }
        pthread_t tid;
        pthread_create(&tid, NULL, func, (void *)&sockfd);
        pthread_join(tid, NULL);
    }


    return 0;
}
