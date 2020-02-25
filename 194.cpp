/*************************************************************************
	> File Name: 194.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月21日 星期三 14时11分51秒
 ************************************************************************/

#include<stdio.h>

#define max_n 100000

int num[max_n + 5] = {0};

int n, s, temp[max_n + 5] = {0}, flag = 0;

int half(int y) {
    int left = 1, right = n, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(num[mid] == y) return 1;
        if(num[mid] > y) {
            right = mid - 1;
        }
        if(num[mid] < y) {
            left = mid + 1;
        }
    }
    return 0;
}

int func(int x) {
    if(half(s - x)) return 1;
    return 0;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    scanf("%d", &s);
    for(int i = 1; i <= n; i++) {
        temp[i] = func(num[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(temp[i] == 1) {
            flag = 1;
        }
    }
    if(flag == 1) {
        printf("Yes");
    }else{
        printf("No");
    }

}
