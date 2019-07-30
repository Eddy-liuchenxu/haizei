/*************************************************************************
	> File Name: 146.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 16时58分01秒
 ************************************************************************/

#include<stdio.h>


int main() {
    int i;
    char ch[50];
    scanf("%s",ch);
    for(i = 0;i < 50;i++){
        if(ch[i] >= 65 && ch[i] < 90){
         ch[i] = ch[i] + 1;
    }
       else if(ch[i] >= 97 && ch[i] < 122) {
        ch[i] = ch[i] + 1;
        }
       else if(ch[i] == 90){
        ch[i] = 'A';
        }
       else if(ch[i] == 122){
        ch[i] = 'a';
        }
    }
    printf("%s",ch);
}
