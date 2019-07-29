/*************************************************************************
	> File Name: 139.c
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 13时54分12秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int n,i,j,I,J;
    scanf("%d", &n);
    for(i = 1,I = 2 * n -1;i <= I;i++){
        for(j = 0,J = abs(n - i);j < J;j++ ){
         printf(" ");
    }
        for(j = 0,J =2 * n - 2* abs(n - i );j < J;j++){
        printf("A");
        
        }
        printf("\n");
    }
}
