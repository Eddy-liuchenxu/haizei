/*************************************************************************
	> File Name: 42.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时56分46秒
 ************************************************************************/

#include<stdio.h>

int num[21] = {0};
long long f[21][10005] = {0};

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &num[i]);
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            f[i][0] = 1;
             f[i][j] = f[i - 1][j];
            if(j >= num[i]) f[i][j] +=  f[i][j - num[i]];
            f[i][j] %= 9973;
        }
    }
    printf("%lld", f[m][n]);
}
