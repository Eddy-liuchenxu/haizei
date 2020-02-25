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
    int n, temp;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        if(num[i] == 100) {
            b[1] += 1;
        } else if(num[i] >= 90 && num[i] <= 99) {
            b[2] += 1;
        } else if(num[i] >= 80 && num[i] <= 89) {
            b[3] += 1;
        } else if(num[i] >= 70 && num[i] <= 79) {
            b[4] += 1;
        } else if(num[i] >= 60 && num[i] <= 69) {
            b[5] += 1;
        }else{
            b[6] += 1;
        }
    }
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(num[j] < num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%d\n", num[i]);
    }
    for(int i = 1; i <= 6; i++) {
        (i - 1) && printf(" ");
        printf("%d", b[i]);
    }

}
