/*************************************************************************
	> File Name: s.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月24日 星期二 18时59分50秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid,x;
    for(int i = 1; i <= 10; i++) {
        if((pid = fork()) < 0) {
            perror("fork()");
            continue;
        }
        if(pid == 0) {
            x = i;
            break;
        }
    }
    printf("i am %dth child.\n",x);
    sleep(60);
    return 0;
}
