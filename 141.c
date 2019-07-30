/*************************************************************************
	> File Name: 141.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 15时00分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,i,j,s,S  ;
    scanf("%d", &n);
    for(i = 1;i <= 2 * n + 1;i++ ) {
        for(j = 1;j <= n - abs(n + 1 - i);j++) {
        printf(" ");
        }
        char ch = 'A' + n;
        for(s = 1,j = n + 1 -abs(n + 1 - i);s <= 2 * abs(n + 1 - i) + 1; s++,j++ ) {
            S = abs(n + 1 - j);
            printf("%c", ch - S);
        
        }
           printf("\n");
    
    }
}
