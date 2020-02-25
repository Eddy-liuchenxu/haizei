/*************************************************************************
	> File Name: 187.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月04日 星期日 16时09分23秒
 ************************************************************************/

#include<stdio.h>

long long f(long long n) {
    if(n == 1) return 1;
    return 2 * f(n - 1) + 1;
}

long long g(long long n) {
    if(n == 1) return 1;
    return n  + 2 * g(n  - 1);
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld %lld", f(n), g(n));
}
