/*************************************************************************
	> File Name: 183.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 17时15分30秒
 ************************************************************************/

#include<stdio.h>

int func(int x) {
    if(x <= 0) return 0;
    if(x ==1) return 1;
    if(x > 1 && x % 2 == 0) return 3 * func(x / 2) - 1;
    if(x > 1 && x % 2 == 1) return 3 * func((x + 1) / 2) - 1;
}

int main() {
    int x;
    scanf("%d",&x);
    printf("%d",func(x));
}
