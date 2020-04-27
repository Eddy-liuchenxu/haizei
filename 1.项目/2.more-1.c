/*************************************************************************
	> File Name: 2.more-1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月21日 星期六 20时00分53秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<termios.h>
#define PAGELINE 15
#define LENLINE 512

void do_more(FILE *fp);
int get_cmd(FILE *);

int length;

int main(int argc, char *argv[]) {
    FILE *fp;
        //获取屏幕宽度
    struct winsize size;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    length = size.ws_row;
    if (argc == 1) do_more(stdin);
    else        
    while (--argc) {
            if ((fp = fopen(*++argv, "r")) != NULL) {
                do_more(fp);
            }
        }

    return 0;
}

void do_more(FILE *fp) { 
    char line[LENLINE] = {0};
    FILE *cmd = fopen("/dev/tty","r");
    int num_line = 0, reply,flag = 0;
    while (fgets(line, LENLINE, fp)) {
        if (num_line == length) {
            reply = get_cmd(cmd);
            if (reply == 0) break;
            num_line -= reply;
        }
        if (fputs(line, stdout) == EOF) {
            perror("fputs");
            exit(1);
        }
        num_line++;
    }
} 

int get_cmd(FILE *fp) {
    printf("more:");
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == 'q') return 0;
        if (c == ' ') return length;
        if (c == '\n') return 1;
    }
    return -1;
}

