/*************************************************************************
	> File Name: 213.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月13日 星期二 22时52分10秒
 ************************************************************************/
#include<iostream>
#include<cstdio>

using namespace std;

int num[35] = {0};
int b[7] = {0};
int main() {
    int n, temp, k;
    double sum;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &k);
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(num[j] < num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    for(int i = 1; i <= k; i++) {
        sum +=(double) num[i];
    }
    
    printf("%.2lf", sum / k);

}
