/*************************************************************************
	> File Name: 465.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时41分45秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int f(long long n , int k) {
    int dight = floor(log10(n) + 1);
    if(dight < k) return 0;
    return n / (int)pow(10,(k - 1)) % 10; 
}

int main() {
    long long n;
    int k;
    scanf("%lld%d", &n,&k);
    printf("%d", f(n,k));

}
