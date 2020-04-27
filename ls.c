/*************************************************************************
	> File Name: ls.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月15日 星期日 19时00分43秒
 ************************************************************************/

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
int temp = 0;
void do_ls(char[]);
char str[1002][100] = {0};
int len = 0;
int length = 0;
int s = 0;
int main(int argc,char *argv[]) {

    //获取屏幕宽度
    struct winsize size;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    length = size.ws_col;

    if(argc == 1) {
        do_ls(".");
    } else{
        while(--argc) {
            printf("%s : \n",*++argv);
            do_ls(*argv);
        }
    }
    return 0;
}

void do_ls(char dirname[] ){
    DIR *dirp;
    struct dirent *direntp;
    if((dirp = opendir(dirname)) == NULL) {
        perror("opendir");
        return;
    }
    s = 0;
    temp = 0;
    while((direntp = readdir(dirp)) != NULL) {
        sprintf(str[s],"%s",direntp->d_name);
        if(strlen(str[s]) > temp){
            temp = strlen(str[s]);
         }
        s++;
        len++;
    }
    s = 0;
    /*
    while(len--) {
        printf("%s",str[s]);
        s++;
    }*/
/*    s = 0;
    while(str[s]) {
        printf("%s",str[s]);
        s++;
    }*/
    while(len--){
    for(int i = 1; i <= length / temp - 1; i++) {
        if(len == 0) break;
        printf("%s",str[s]);
        int times = strlen(str[s]);
        while(times <= temp) {
            printf(" ");
            times++;
        }
            s++;
            len--;
    }
        printf("\n");
    }
    closedir(dirp);
}

