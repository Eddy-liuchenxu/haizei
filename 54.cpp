/*************************************************************************
	> File Name: 54.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 15时39分34秒
 ************************************************************************/
#include<stdio.h>

#define max_n 100000
int main() {
    int n;
    while(~scanf("%d", &n) != EOF) {
        int num[max_n + 5] = {1, 1};
        int ans[max_n + 5] = {1, 1};
    for(int i = 1; i <= n; i++) {
        for(int j = num[0]; j >= 1; j--) {
            num[j] *= i;
        }
        for(int j = 1; j <= num[0]; j++) {
            if(num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }


        for(int i = num[0]; i >= 1; i--) {
            if(num[i] != 0) {
                for(int j = ans[0]; j >= 1; j--) {
                    ans[j] *= num[i];
                }
                for(int j = 1; j <= ans[0]; j++) {
                    if(ans[j] < 10) continue;
                    ans[j + 1] += ans[j] / 10;
                    ans[j] %= 10;
                    ans[0] += (j == ans[0]);
                }
            }
        }
        for(int i = ans[0]; i >= 1; i--) {
            printf("%d", ans[i]);
            if(i == 1) printf("\n");
        }
    }
    return 0;
}
