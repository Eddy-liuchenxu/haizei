/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年04月04日 星期六 23时26分13秒
 ************************************************************************/

#include <stdio.h>
int f(int a){
    int b = 0;
   static  int c = 3;
    a = c++,b++;
    return a;
}
int main(){
    int a = 2;
    int k;
    for(int i = 0; i < 2; i++){
        k=f(a++);
    }
    printf("%d",k);
}
