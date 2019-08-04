/*************************************************************************
	> File Name: 186.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 20时53分38秒
 ************************************************************************/

#include<stdio.h>

int f(int n, int a[]) {
    int sum = 0, s = 1;
    for(int i = 1; n >= s;i = s ) {
        s = s + a[i];
        sum += 1;
    }
    return sum;
}

int main() {
    int n,i, a[100000] = {0};
    scanf("%d", &n);
    for(i = 1;i <= n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d", f(n, a));
}
