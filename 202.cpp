/*************************************************************************
	> File Name: 202.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月13日 星期二 22时16分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>

int num[1005] = {0};
int change[1005] = {0};

int main() {
    int n;
    for(int i = 1; i <= 1000; i++) {
        change[i] = i;
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    int temp;
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(num[j] > num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;

                temp = change[j];
                change[j] = change[j + 1];
                change[j + 1] = temp;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        (i - 1) && printf(" ");
        printf("%d", change[i]);
    }


}
