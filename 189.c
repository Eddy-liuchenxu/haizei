/*************************************************************************
	> File Name: 189.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月04日 星期日 20时37分57秒
 ************************************************************************/

#include<stdio.h>

int n, k;

int f(int a[],int i) {
    int left = 0, right = n;
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(a[mid] == i) return mid + 1;
        if(a[mid] > i) right = mid - 1;
        if(a[mid] < i) left = mid + 1;
    }
    return 0;

}

int main() {
    int a[1000005] = {0}, b[1000005] = {0};
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < k; i++) {
        i && printf(" ");
        printf("%d", f(a, b[i]));
    }

}
