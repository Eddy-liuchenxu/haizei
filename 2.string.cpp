/*************************************************************************
	> File Name: 2.string.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月12日 星期四 20时34分33秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    char str[100];
    while(~scanf("%d", &n)) {
        printf("%s has %d digits",str, sprintf(str, "%x", n));
    }
}
