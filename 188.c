/*************************************************************************
	> File Name: 188.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月04日 星期日 16时48分42秒
 ************************************************************************/

#include<stdio.h>

int swap(int &n,int &m){
    int t;
    if(n < m){
        t = n;
        n = m;
        m = t;
    }
}

int main() {
    int n, m, a[1000002] = {0};
    scanf("%d%d",&n, &m);
    swap(n,m);
    for(int i = 2;i * i <= 1000000;i++) {
        if(a[i] == 0){
            for(int j = 2; i * j <= 1000000; j++) {
                a[i * j] = 1;
            }
        }
    }
    for(int i = m;i <= n; i++) {
        if(a[i] == 0) {
            printf("%d\n", i);
        }
    }


}
