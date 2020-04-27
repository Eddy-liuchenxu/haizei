/*************************************************************************
	> File Name: pthread.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 19时50分14秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
struct Msg{
    int age;
    char name[20];
};

void *print(void *arg){
    struct Msg *tmp;
    tmp = (struct Msg *)arg;
    printf("%s\n",tmp->name);
    return NULL;
}

int main(){
    pthread_t tid;
    struct Msg msg;
    msg.age = 18;
    strcpy(msg.name,"liu");
    pthread_create(&tid,NULL,print,(void *)&msg);
    sleep(1);
    return 0;

}
