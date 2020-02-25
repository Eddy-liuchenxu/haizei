/*************************************************************************
	> File Name: 191.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 13时34分33秒
 ************************************************************************/

#include<stdio.h>

int a = 0, b = 0, c = 0, d = 0;
int x[8000000] = {1, 1};

int f(int l, int r) {
    int min = 8000000 ,max = 0;
    for(int i = 2; i  <= r; i++) {
        if(!x[i]) {
            for(int j = 2; j * i <= r; j++) {
                x[i * j] = 1;
            }
        }
    }
    for(int i = l; i <= r; i++) {
     if(!x[i]) {
         for(int j = i + 1; j <= r; j++){
         if(!x[j]){
            if(max < j - i){
                max = j - i;
                c = i;
                d = j;
            }
            if(!x[j]){
            if(min > j - i){
                min = j - i;
                a = i;
                b = j;
            }
            }    
            break;
         }
         }
        }
    }
}

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    f(l, r);
    if(a == 0) {
        printf("There are no adjacent primes.");
    }else {
        printf("%d,%d are closest, %d,%d are most distant.", a, b, c ,d );
    }
}


