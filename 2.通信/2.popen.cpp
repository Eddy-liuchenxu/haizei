/*************************************************************************
	> File Name: 2.popen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月09日 星期四 17时19分39秒
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
		char cmdString[50] = "";
		for(int i=1;i<argc;i++){
			strcat(cmdString,argv[i]);
			strcat(cmdString," ");
		}	
		strcat(cmdString,"> ");
		strcat(cmdString,CACHEFILE);
		
		pid_t commond_pid = fork();
		if(commond_pid == 0){
		   // execl("/bin/bash","bash","-c",cmdString,(char*)0);
            execlp(argv[1],cmdString,NULL);
		    perror("execl");
			exit(0);
		}else{
			waitpid(-1,0,0);
		}
 
		FILE *fp = 0;
		if((fp=fopen(CACHEFILE,"r"))==NULL){
			perror("open file");
			_exit(EXIT_FAILURE);
		}
		else{
			int size = fread(buffer,1,BUFFERSIZE,fp);
 
			write(fd[1],buffer,size);
			fclose(fp);
			if(remove(CACHEFILE) == -1){
				perror("remove");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
	}else{
		waitpid(-1,0,0);
		memset(buffer,0,BUFFERSIZE);
		int size = read(fd[0],buffer,BUFFERSIZE);
		write(1,buffer,size);
	}
	close(fd[0]);
	close(fd[1]);
	return 0;
}
