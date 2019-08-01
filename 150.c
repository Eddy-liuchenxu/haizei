/*************************************************************************
	> File Name: 150.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月01日 星期四 20时45分07秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int m, n, i, j;
    int a[205][205];
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i = 0; i < m; i++){
        for(j = n - 1; j >= 0; j--) {
            if(j != n - 1) printf(" ");
            printf("%d", a[j][i]);
        }
        printf("\n");
    }
}
