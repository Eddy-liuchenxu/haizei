/*************************************************************************
	> File Name: 2.more.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月21日 星期六 19时29分07秒
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#define PAGELINE 15
#define LENLINE 512

void do_more(FILE *fp);
int get_cmd();
int main(int argc,char ** argv) {
    FILE *fp;
    if(argc == 1){
        printf("Usage : %s [filename | stdin]\n",argv[0]);
    }else{
        while(--argc){
            if((fp = fopen(*++argv,"r")) != NULL){
                do_more(fp);
            }
        }
    }
    return 0;    

}

void do_more(FILE *fp){
    char line[LENLINE] = {0};
    int num_line = 0,reply;
    while(fgets(line,LENLINE, fp)) {
        if(num_line == PAGELINE) {
            reply = get_cmd();
            if(reply == 0) break;
        }
        if(fputs(line,stdout) == EOF){
            perror("fputs");
            exit(1);
        }
        num_line++;
    }
}

int get_cmd() {
    printf("more:");
    char c;
    while((c = getchar())!=EOF){
        if(c == 'q') return 0;
        if(c == ' ') return 1;
        if(c == '\n') return 2;
    }
    return -1;
}
