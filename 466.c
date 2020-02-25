/*************************************************************************
	> File Name: 466.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时31分55秒
 ************************************************************************/

#include<stdio.h>

int f(int n) {
    int temp = n,s = 0;
    while(n) {
        s = n % 10 + s* 10; 
        n = n / 10;
        
    }
    return temp == s;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for(int  i = 1; i <= n; i++) {
        if(f(i)) ans++;
    }
    printf("%d",ans);

}
