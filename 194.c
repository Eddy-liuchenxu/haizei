/*************************************************************************
	> File Name: 194.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 20时51分49秒
 ************************************************************************/

#include<stdio.h>

long long a[100005] = {0}, s;
int left = 0, right , mid;

int g(int x) {
    return s - x;
}

int f(long long s) {
    mid = (left + right) / 2;
    if(g(mid) > 0) {
       for(int i = 0; i < mid; i++) {
        if(g[mid] == a[i]) return 1;
       } 
    }
}

int main() {
    int n;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &s);
    if(f(s)) {
        printf("Yes");
    } else {
        printf("N0");
    }
}

