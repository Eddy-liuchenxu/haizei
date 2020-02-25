/*************************************************************************
	> File Name: 451.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 23时57分37秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

#define max_n 100000
int num[max_n + 5] = {0};

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
        printf("%d\n", num[i]);
    }
}
