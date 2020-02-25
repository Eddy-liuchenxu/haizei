/*************************************************************************
	> File Name: 215.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 18时04分27秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

char name[45][15];
char change[15] = {0};
int sum[45] = {0};
int main() {
    memset(name, 0, sizeof(name));
    int n, ma, ch, en, go, temp;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", name[i]);
        scanf("%d %d %d %d", &ma, &ch, &en, &go);
        sum[i] = ma + ch + en + go;
    }
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(sum[j] < sum[j + 1]) {
                temp = sum[j];
                sum[j] = sum[j + 1];
                sum[j + 1] = temp;
                strcpy(change, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], change);
            }
        }
    }
    for(int i = 1; i <= 3; i++) {
        printf("%s\n", name[i]);
    }


}
