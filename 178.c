/*************************************************************************
	> File Name: 178.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月03日 星期六 00时13分48秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int f(int n) {
    if(n == 1) return 1;
    return 2 * f(n-1) + 1;
}

int main() {
    int n;
    long long i;
    scanf("%d",&n);
    char ch[1000000] = {0};
    for( i = 1; i <=  f(n); i++) {
        if(i % 8 == 1) {
            ch[i - 1] = 'A';
        }
        if(i % 8 == 2) {
            ch[i - 1] = 'B';
        }
        if(i % 8 == 3){
            ch[i - 1] = 'A';
        }
        if(i % 8 == 4) {
            ch[i - 1] = 'C';
        }
        if(i % 8 == 5) {
            ch[i - 1] = 'A';
        }
        if(i % 8 == 6) {
            ch[i - 1] = 'B';
        }
        if(i % 8 == 7) {
            ch[i - 1] = 'A';
        }
        if(i % 16 == 8) {
            ch[i - 1] = 'D';
        }
        if(i % 16 == 0) {
            ch[i - 1] = 'E';
        }

    }
    for(i = 0; i < strlen(ch); i++)
    printf("%c", ch[i]);
}
