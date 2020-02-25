/*************************************************************************
	> File Name: 462.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 16时28分44秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max_n 10000
char ch[max_n + 5][25] = {0};
long long  num[20] = {0};
int main() {
    int n;
    int men = 0, women = 0;
    long long s = 0, ans = 0,sum;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        scanf("%[^\n]s", ch[i]);
        getchar();
        int len = strlen(ch[i]);
        if(ch[i][0] == 'i') {
            if(ch[i][len - 2] % 2 == 0) {
                women += 1;
            }else {
                men += 1;
            }
        }
        if(ch[i][0] = 'q') {
            s += 1; 
            for(int j = 2; j <= 9; j++) {
                sum = sum * 10 + (ch[i][j] - '0');
            }
            ans  += sum;
        }
        
    }
    ans = ans / s;
    printf("%d %d %lld", men,women,ans);
    }

