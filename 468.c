/*************************************************************************
	> File Name: 468.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时27分45秒
 ************************************************************************/

#include<stdio.h>

int gcd(int m,int n) {
    if(n == 0) return m;
    return gcd(n,m%n);
}

int main () {
    int m ,n;
    scanf("%d%d",&m,&n);
    printf("%d", gcd(m,n));
}
