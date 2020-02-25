/*************************************************************************
	> File Name: 54-3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 18时04分18秒
 ************************************************************************/

#include<string.h>
#include <stdio.h>
#define max_n 10000
int x;
int num[max_n + 5]= {1, 1};
int ans[max_n + 5]= {1, 1};
void funa(int n) {
    for(int i = 1; i <= ans[0]; i++)
    ans[i] *= n;
    for(int i = 1; i <= ans[0]; i++) {
        if(ans[i] < 10) continue;
        ans[i + 1] += ans[i] / 10;
        ans[i] = ans[i] % 10;
        if(i == ans[0]) {
            ans[0]++;
        }
    }
    return;

}
void func() {
    for(int i = 1; i <= x; i++) {
        funa(i);
    }
    return;
}
void te(int n){
    for(int i = 1; i <= num[0]; i++) {
        num[i] *= n;
    }
    return;
}
void f() {
    for(int o = 1; o <= ans[0]; o++) {
       if(ans[o] != 0) {te(ans[o]);}
 for(int i = 1; i <= num[0]; i++) {
        if(num[i] < 10) continue;
        num[i + 1] += num[i] / 10;
        num[i] = num[i] % 10;
        if(i == num[0]) {
            num[0]++;
        }
    }
    }
    return;
}
int main() {
    while(scanf("%d",&x) != EOF){
     memset(num,0,sizeof(num));
        
     memset(ans,0,sizeof(ans));
      num[1]= 1;
        num[0] = 1;
      ans[1]= 1;
        ans[0] = 1;
    func();
    f();
    for(int i = num[0]; i > 0; i--) {
        printf("%d",num[i]);
    }
        printf("\n");
    }
    return 0;
}
