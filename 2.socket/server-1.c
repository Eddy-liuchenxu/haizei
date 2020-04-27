/*************************************************************************
	> File Name: server-1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 00时06分56秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {//如果不是两个参数也就意味着没有问系统要端口
    fprintf(stderr, "Usage : %s port\n", argv[0]);
    exit(1);
  }
  //定义端口
  int port, server_listen;//server_listen作为socket文件描述符
  port = atoi(argv[1]);//将传入的第二个参数转化为整形作为端口号
  
  //启动socket，即向系统申请了一扇门 
if ((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }
  
  printf("Socket_ceate.\n");//输出调试
  //要门牌号
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = INADDR_ANY;//这三行详情请看“相关结构体、要用到的函数”
  if (bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) {
    //如果出错，意味着这个端口号不能给你
    perror("bind");
    exit(1);
  }  
  printf("Socket bind.\n");//输出调试
  //接下来要listen
  if (listen(server_listen, 20) < 0) {
    perror("server");
    exit(1);
  }
  
  while (1) {
    int sockfd;//就相当于NPC
    printf("Socket before accept.\n");//输出调试
    if (sockfd = accept(server_listen, NULL, NULL) < 0) {
      //参数表明不关注是哪个地址
      perror("accept");
      close(sockfd);
      continue;  }
    //如果连接成功了
    //我现在想知道对方的名字，
    printf("Socket After accpet.\n");//输出调试
    char name[20] = {0};
      if (recv(sockfd,name,sizeof(name),0) <= 0) {
      //如果接收名字失败
      close(sockfd);
      continue;
    }
    
    printf("Socket received.\n");//输出调试
    //如果成功收到名字了
    printf("name : %s\n", name);
    //但是这么做很像一个智障，因为如果对方不给我名字，我就会阻塞
    close(sockfd);
  }
  
  return 0;
}

