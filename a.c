/*************************************************************************
	> File Name: a.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 16时06分50秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char **argv){
    int pid,ppid,pppid;
    pid = fork();
    if(pid < 0){
        perror("fork");
        exit(0);
    }
    if(pid == 0){
        execlp("vim","vim",argv[1],NULL);
    }else{
        wait(NULL);
        ppid = fork();
        if(ppid == 0){
            execlp("g++","g++","-o","a",argv[1],NULL);
        }else{
            wait(NULL);
            pppid = fork();
            if(pppid == 0){
                execlp("./a","./a",NULL);
            }else{
                wait(NULL);
            }
        }
    }
    return 0;

}
