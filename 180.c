/*************************************************************************
	> File Name: 180.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 17时56分27秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n,i;
    long long int sum = 1;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        sum *= 2;
    }
    printf("%lld",sum);
}
