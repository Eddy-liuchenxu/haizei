/*************************************************************************
	> File Name: 188.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月19日 星期四 19时15分42秒
 ************************************************************************/
#include<stdio.h>
#define max_n 1000000
int pri[max_n + 5] = {0};
int prime() {
    for(int i = 2; i <= max_n; i++) {
        if(pri[i] == 0) pri[++pri[0]] = i;
        for(int j = 1; j <= pri[0]; j++) {
            if(pri[j] * i > max_n) break;
            pri[pri[j] * i] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}
int main() {
    int n,m;
    long long sum;
    scanf("%d%d", &n,&m);
    prime();
    for(int i = 1; i <= pri[0]; i++) {
        if(pri[i] >= m && pri[i] <= n) printf("%d\n", pri[i]);
    }
    return 0;
}
