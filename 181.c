/*************************************************************************
	> File Name: 181.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 17时40分17秒
 ************************************************************************/

#include<stdio.h>

int main() {
    char ch[1000];
    int i = 0;
    scanf("%s",ch);
    while(ch[i] != '\0') {
        if(ch[i] >= 97 && ch[i] <= 122) {
            printf("%c",ch[i] - 32);
        }
        if(ch[i] >= 65 && ch[i] <= 90) {
            printf("%c", ch[i] + 32);
        }
        i++;
    }
}
