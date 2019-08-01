/*************************************************************************
	> File Name: 148.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月01日 星期四 19时56分54秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
    int i;
    char ch [51];
    scanf("%s",ch);
    for(i = strlen(ch) - 1; i >= 0; i--) {
        printf("%c",ch[i]);
    }
}
