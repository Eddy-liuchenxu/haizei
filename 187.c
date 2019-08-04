/*************************************************************************
	> File Name: 187.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月04日 星期日 16时09分23秒
 ************************************************************************/

#include<stdio.h>

int f(int n) {
    if(n == 1) return 1;
    return 2 * f(n - 1) + 1;
}

int g(int n) {
    if(n == 1) return 1;
    return n  + 2 * f(n  - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d%d", f(n), g(n);
}
