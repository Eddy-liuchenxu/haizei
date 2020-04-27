/*************************************************************************
	> File Name: server-3.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 11时38分41秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include<signal.h>
int main(int argc, char *argv[]) {
    signal(SIGCHLD, SIG_IGN);
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
    exit(1);  }
  
  printf("Socket bind.\n");//输出调试
  //接下来要listen
  if (listen(server_listen, 20) < 0) {
    perror("server");
    exit(1);
  }
  
  while (1) {
    int sockfd;//就相当于NPC
    printf("Socket before accept.\n");//输出调试
    if ((sockfd = accept(server_listen, NULL, NULL)) < 0) {
      //参数表明不关注是哪个地址
      perror("accept");
      close(sockfd);
      continue;
    }
    
    pid_t pid;   if ((pid = fork()) < 0) {
      perror("fork");
      continue;
    }
    
    if (pid == 0) {//如果创建子进程成功，那么在子进程中的pid是被设置为0的
      close(server_listen);
      char name[20] = {0};
      if (recv(sockfd, name, sizeof(name), 0) <= 0) {
        perror("recv");
        close(sockfd);
      }     printf("Name = %s\n", name);
      exit(0);//如果子进程在这不退出，就会继续在While循环里，这不是我们想要的
    }
    
  }
  
  return 0;
}
