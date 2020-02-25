/*************************************************************************
	> File Name: 200.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 17时54分09秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    int a[31] = {0, 4, 7};
    int b[31] = {0, 7, 11};
    double sum = (double)a[1] / (double)b[1] + (double)a[2] / (double)b[2];
    scanf("%d", &n);
    for(int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
        sum = sum + (double)a[i] / (double)b[i];
    }
    printf("%d/%d\n",a[n],b[n]);
    printf("%.2lf",sum);


}
