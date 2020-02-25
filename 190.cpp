/*************************************************************************
	> File Name: 190.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 19时42分43秒
 ************************************************************************/
#include<stdio.h>
#include <iostream>
using namespace std;
#define max_n 8000000
int num[max_n + 5] = {0};
int prime() {
    for(int i = 2; i <= max_n; i++) {
        if(num[i] == 0) num[++num[0]] = i;
        for(int j = 1; j <= num[0]; j++) {
            if(i * num[j] >max_n ) break;
            num[i * num[j]] = 1;
            if(i % num[j] == 0) break;
        }
    }
}
int f(int x, int n) {
    for(int i = 1; i <= num[0]; i++) {
        if(n - x == num[i]) return 1;
        if(n - x < num[i]) break;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d", &n);
    prime();
    int sum = 0;
    for(int i = 1; i <= num[0],num[i] <= n/2; i++) {
        if(f(num[i],n)) sum++; 
    }
    printf("%d", sum);
}
