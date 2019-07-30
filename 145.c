#include <stdio.h>
#include <string.h>

int main() {
    int N,i,j,num,temp,s = 0;
    char ch[21][100];
    scanf("%d", &N);
    for(i = 1;i <= N;i ++) {
        scanf("%s",ch[i]);
        temp = strlen(ch[i]);
       if(temp > s) { s = temp;num = i ;}
    }
    printf("%s", ch[num]);
}
