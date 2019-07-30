/*************************************************************************
	> File Name: 184.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 17时30分12秒
 ************************************************************************/

#include<stdio.h>

int func(int x,int n) {
    if(n == 1) return x;
    return func((x+1)*2,n-1);
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d",func(1,n));

}
