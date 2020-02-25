/*************************************************************************
	> File Name: 450.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 23时42分54秒
 ************************************************************************/

#include<stdio.h>

int num[105] = {0};

int sort(int n, int num[]) {
    int temp;
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(num[j] > num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    sort(n,num);
    for(int i = 1; i <= n; i++) {
        (i - 1) && printf(" ");
        printf("%d", num[i]);
    }
}
