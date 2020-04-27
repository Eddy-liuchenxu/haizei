/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时21分57秒
 ************************************************************************/

#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char **argv){
    int sockfd,port;
    struct sockaddr_in server;
    if(argc != 3){
        fprintf(stderr, "usage %s\n",argv[0]);
        exit(1);
    }
    port = atoi(argv[2]);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socker");
        exit(1);
    }
    printf("socker create\n");
    if(connect(sockfd,(struct sockaddr *) &server,sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }
    if(send(sockfd,"liuchexu",sizeof("liuchexu"),0) < 0){
        perror("send");
        exit(1);
    }
    close(sockfd);

}
