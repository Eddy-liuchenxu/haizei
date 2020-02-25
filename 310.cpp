/*************************************************************************
	> File Name: 310.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月29日 星期日 19时11分57秒
 ************************************************************************/
#include<algorithm>
#include <iostream>
using namespace std;
#define max_n 1000000
int prime[max_n + 5];
void init_prime() {
    for(int i = 2; i <= max_n ; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max_n) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return;
}
int main() {
    init_prime();
    int n;
    cin >>n;
    for(int i = 1; i <= prime[0] && prime[i] <= n; i++) {
        long long cnt = 0;
        for(long long j = prime[i]; j <= n; j *= prime[i]) {
            cnt += n / j;
        }
        cout << prime[i] << " " << cnt << endl;
    }
    return 0;
}
