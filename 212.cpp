/*************************************************************************
	> File Name: 212.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月13日 星期二 22时39分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>

char ch[20][25] = {0};
char temp[25] = {0};
int main() {
    for(int i = 1; i <= 10; i++) {
        scanf("%s", ch[i]);
    }
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 10 - i; j++) {
            if(strcmp(ch[j] , ch[j + 1]) > 0) {
                strcpy(temp, ch[j]);
                strcpy(ch[j], ch[j + 1]);
                strcpy(ch[j + 1], temp);
            }
        }
    }
    for(int i = 1; i <= 10; i++) {
        printf("%s\n", ch[i]);
    }
}
