/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月02日 星期四 12时06分17秒
 ************************************************************************/

#include <stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>

#define PORT 8888
#define IP "169.254.9.84"

char buf[1024],filename[1024];

int main(){
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port =  htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);
    int s_fd = socket(AF_INET,SOCK_STREAM,0);
    if(bind(s_fd,(struct sockaddr *)&server_addr,sizeof(server_addr))){
        exit(1);
    }
    listen(s_fd,10);
    while(1){
        struct sockaddr_in client_addr;
        int length = sizeof(client_addr);
        int s_fd2 = accept(s_fd,(struct sockaddr*) &client_addr,&length);
        memset(buf,0,sizeof(buf));
        recv(s_fd2,buf,sizeof(buf),0);
        memset(filename,0,sizeof(filename));
        strcpy(filename,buf);
        FILE *fp = fopen(filename,"r");
        memset(buf,0,sizeof(buf));
        int buf_size = 0;
        while((buf_size = fread(buf,sizeof(char),1000,fp))> 0){
            send(s_fd2,buf,buf_size,0);
            memset(buf,0,sizeof(buf));
        }
        fclose(fp);
        close(client_addr);
    }
    close(server_addr);
    return 0;

}
