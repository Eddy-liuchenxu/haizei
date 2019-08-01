/*************************************************************************
	> File Name: 147.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月01日 星期四 19时15分50秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main() {
   char n[25000];
    scanf("%s",n);
    if((n[strlen(n)-1]-'0')%2){
    printf("NO");
    }else{
    printf("YES");}
}
