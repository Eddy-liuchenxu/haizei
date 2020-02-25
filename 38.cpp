/*************************************************************************
	> File Name: 38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 20时23分18秒
 ************************************************************************/

#include<stdio.h>

#define max_n 100
int f[max_n + 5][max_n + 5] = {{1, 0},{1, 1},{1, 1}, {1, 2}};
int s[max_n + 5][max_n + 5] ={{1, 0}, {1, 1}, {1, 1},{1, 2}};
int name[max_n + 5] = {0};
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= f[0][0]; j++) {
            f[i][j] = f[i - 1][j] + f[i - 2][j];
        } 
        for(int j =1; j <= f[0][0]; j++) {
            if(f[i][j] < 10) continue;
            f[i][j + 1] += f[i][j] / 10;
            f[i][j] %= 10;
            f[0][0] += (j == f[0][0]);
        }
    }
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= s[0][0]; j++) {
            s[i][j] = s[i - 1][j] + s[i - 2][j];
        } 
        for(int j =1; j <= s[0][0]; j++) {
            if(s[i][j] < 10) continue;
            s[i][j + 1] += s[i][j] / 10;
            s[i][j] %= 10;
            s[0][0] += (j == s[0][0]);
        }
    }
    for(int i = 1; i <= f[0][0]; i++) {
        f[n][i] *= 4;
    }
    for(int j =1; j <= f[0][0]; j++) {
            if(f[n][j] < 10) continue;
            f[n][j + 1] += f[n][j] / 10;
            f[n][j] %= 10;
            f[0][0] += (j == f[0][0]);
        } 

    for(int i = 1; i <= s[0][0]; i++) {
        s[n][i] *= 2;
    }
    for(int j =1; j <= s[0][0]; j++) {
            if(s[n][j] < 10) continue;
            s[n][j + 1] += s[n][j] / 10;
            s[n][j] %= 10;
            s[0][0] += (j == s[0][0]);
        }
    int temp;
    if(s[0][0] > f[0][0]) {
        temp = s[0][0];
    } else {
        temp = f[0][0];
    }
    for(int i = 1; i <= temp; i++) {
        name[i] = s[n][i] + f[n][i];
    }
    for(int j =1; j <= temp; j++) {
            if(name[j] < 10) continue;
            name[j + 1] += name[j] / 10;
            name[j] %= 10;
            temp += (j == temp);
        } 
    for(int i = temp; i >= 1; i--) {
        printf("%d", name[i]);
    }
}
