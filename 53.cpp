/*************************************************************************
	> File Name: 53.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 15时42分15秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

#define max_n 1000000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};
int fac[max_n + 5] = {0};
int main() {
    int ans = 0;
    for(int i = 2; i <= max_n; i++) {
        if(prime[i] == 0){
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
            fac[i] = 1 + i;
        }
        for(int j = 1;j <= prime[0]; j++) {
            if(prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
               fac[prime[j] * i] = fac[i] / (pow (prime[j] , cnt[i] + 1) - 1) * (pow (prime[j], cnt[i]+ 2) - 1);
                f[prime[j] * i] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[prime[j] * i] = cnt[i] + 1; 
            }else{
                fac[i * prime[j]] = fac[i] * fac[prime[j]];
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[prime[j] * i] = 1;
            }
            if(fac[i * prime[j]] > ans) {
                ans= fac[i * prime[j]];
            }
        }
    
    }
    cout << ans << endl;
}
