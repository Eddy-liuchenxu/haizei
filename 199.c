/*************************************************************************
	> File Name: 199.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月07日 星期三 11时18分51秒
 ************************************************************************/

#include<stdio.h>

long long  a[11] = {0}, num[100005] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    int k, m;
    scanf("%d%d",&k, &m);
    for(int i = 1;i <= 10; i++) {
        scanf("%lld", &a[i]);
    }
    if(k >= 10) {
    for(int j = 10; j <= k; j++) {
num[j]=(a[1] * num[j - 1]+a[2]*num[ j - 2] + a[3] * num[j - 3] + a[4] * num[j - 4] + a[5] * num[j - 5] + a[6] * num[j - 6] + a[7] * num[j - 7] + a[8] * num[j - 8] + a[9] * num[j - 9] + a[10] * num[j - 10]) % m; 
    }
    }
    printf("%lld", num[k]);

        
}
