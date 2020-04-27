/*************************************************************************
> File Name: sock_connect_timeout.cpp
> Author: 
> Mail: 
> Created Time: 2020年04月11日 星期六 11时01分17秒
************************************************************************/
#include  "head.h"

int socket_connect_timeout(char *host, int port) {
    fd_set rfds;
    struct timeval tv;
    int sockfd;
    struct sockaddr_in server;
    int retval;
    int ret;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }   
    printf("Socket create.\n");
    if ( connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("connect");
        exit(1);
    }
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    ret = select(sockfd + 1, &rfds, NULL, NULL, &tv);
    if(ret = 1){
        printf("connect");
    }
