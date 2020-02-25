/*************************************************************************
	> File Name: 467.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时20分32秒
 ************************************************************************/

#include<stdio.h>


long long f(int n) {
    if(n == 1) return 1;
    return n * f(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(n));
}
