/*************************************************************************
	> File Name: 197.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 21时00分42秒
 ************************************************************************/

#include<stdio.h>
#define number 10

int main() {
    int a[10] = {0}, t;
    for(int i = 0; i < number; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < number - 1; i++) {
        for(int j = 0; j < number - i - 1; j++) {
            if(a[j] < a[j + 1] ) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for(int i = 0; i < number; i++) {
        i && printf(" ");
        printf("%d", a[i]);
    }
}
