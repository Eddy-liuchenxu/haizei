/*************************************************************************
	> File Name: exec.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 18时13分09秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv){
    pid_t pid;
    char o_name[512] = {0};
    char filename[512] = {0};
    char f_type[256] = {0};
    char cmd[512] = {0};
    if(argv < 2){
        fprintf(stderr,"usage:%s filename arg...\n",argv[0]);
        return 1;
    }
    strcpy(filename,argv[1]);
    char *sub;
    sub = strstr(filename,".");

    strncpy(o_name, filename, sub-filename);

    strcpy(f_type,sub);

    if(!strcmp(f_type,".c")){
        strcpy(cmd,"gcc");
    }else if(!strcmp(f_type,".cpp")){
        strcpy(cmd,"g++");
    }else{
        fprintf(stderr,"not suport file type\n");
        return 2;
    }

    if((pid = fork())< 0 ){
				perror("fork");
				return 3;
			}
    if(pid == 0){
        execlp("vim","vim",filename,NULL);
    }
    if((pid = fork())< 0){
        perror("fork");
        return 3;
    }
    if(pid == 0){
        execlp(cmd,cmd,filename,"-o",o_name,NULL);
    }
    int status;
    wait(&status);
    if(status == 0){
        printf("OK\n");
        char name[25] = {0};
        sprintf(name,"./%s",o_name);
        execlp(name,o_name,NULL);
    }else{
        printf("Failed!\n");
        return 4;
    }
    wait(NULL);
}
