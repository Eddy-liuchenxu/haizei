/*************************************************************************
	> File Name: 177.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月03日 星期六 10时51分18秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int f(char ch[]) {
    char a[27] = {0};
    a[0] = ch[strlen(ch) - 2];
    a[1] = ch[strlen(ch) - 1];
    for(int i = 2; i < strlen(ch); i++){
        a[i] = ch[i - 2];
    }
    strcpy(ch, a);
    for(int i = 0; i < strlen(ch); i++) {
        printf("%c",ch[i]);
    }
    printf("\n");
}

int main() {
    int i;
    char ch[27];
    scanf("%s",ch);
    for(i = 0; ch[i]; i++) {
        printf("%c",ch[i]);
    }
        printf("\n");
    for(i = 0; i < strlen(ch) -1; i++) 
        f(ch);
}
