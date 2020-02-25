/*************************************************************************
	> File Name: 216.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 18时26分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char name[105][105];
char change[105][105];
int len[105] = {0};
char temp[105] = {0};
int main() {
    memset(name, 0, sizeof(name));
    memset(change, 0, sizeof(change));
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", name[i]);
        len[i] = strlen(name[i]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 3; j <= len[i]; j++) {
            change[i][j - 3] = name[i][j];
        }
    }
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(strcmp(change[j + 1], change[j]) < 0) {
                strcpy(temp, change[j]);
                strcpy(change[j], change[j + 1]);
                strcpy(change[j + 1], temp);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%s\n", change[i]);
    
    }


}
