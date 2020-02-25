/*************************************************************************
	> File Name: 190.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月04日 星期日 21时01分39秒
 ************************************************************************/

#include<stdio.h>

int a[8000000] = {1,1};

int f(int n) {
    int flag,s = 0,y, sum = 0;
    for(int i = 2; i*i <= n; i++) {
        if(!a[i])
        for(int j = 2; i * j <= n ; j++) {
             a[i * j] = 1;
        }
    }
    for(int i = 2; i <= n / 2 ; i++) {
        if(!a[i] && !a[n -i]) {
            sum++;
        }
        }
    
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
}
