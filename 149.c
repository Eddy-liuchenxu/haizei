/*************************************************************************
	> File Name: 149.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月01日 星期四 20时12分06秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char ch[51],a[1] = {'/0'};
    gets(ch);
    for(i = strlen(ch);i >= 0; i--) {
        if(ch[i] == ' ') {
           printf("%d", strlen(ch)-i-1);
            break;
        }
    }
    
}
