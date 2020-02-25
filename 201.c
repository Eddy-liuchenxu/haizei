/*************************************************************************
	> File Name: 201.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 19时44分52秒
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define max_n 100

int a[max_n + 5] = {0}; 
int ans[max_n + 5] = {0};

int main() {
    int n,sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(a[j] == a[j +1]) a[j] = -1;
            if(a[j] > a[j + 1]) {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] > 0) {
            ans[sum] = a[i];
            sum++;
        }
    }
    printf("%d\n", sum);
    for(int i = 0; i < sum; i++) {
        i  && printf(" ");
        printf("%d", ans[i]);
        }
}
