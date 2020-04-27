/*************************************************************************
> File Name: mypopen-2.cpp
> Author: 
> Mail: 
> Created Time: 2020年04月11日 星期六 01时46分46秒
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFERSIZE 65535
#define CACHEFILE "/tmp/x.temp"

int main(int argc,char **argv){
    int fd[2];
    char buffer[BUFFERSIZE];
    pipe(fd);
    pid_t pid = fork();
    if(pid == 0){
        char cmdString[50];
        for(int i=1;i<argc;i++){
            strcat(cmdString,argv[i]);
            strcat(cmdString," ");
        }	
        strcat(cmdString,"> ");
        strcat(cmdString,CACHEFILE);

        pid_t commond_pid = fork();
        if(commond_pid == 0){
            execl("/bin/bash","bash","-c",cmdString,NULL);
            //execlp(argv[1],cmdString,NULL);
            perror("execl");
            exit(0);
        }
        wait(NULL);
        FILE *fp;
        if((fp=fopen(CACHEFILE,"r"))==NULL){
            perror("fopen");
            exit(1);
        }

        close(fd[0]);
        int size = fread(buffer,1,BUFFERSIZE,fp);
        write(fd[1],buffer,size);
        fclose(fp);
        close(fd[1]);
        exit(0);

    }
    wait(NULL);
    close(fd[1]);
    memset(buffer,0,BUFFERSIZE);
    int size = read(fd[0],buffer,BUFFERSIZE);
    write(STDOUT_FILENO,buffer,size);
    close(fd[0]);
    return 0;
}


