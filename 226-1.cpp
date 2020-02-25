/*************************************************************************
	> File Name: 226-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月29日 星期日 18时43分41秒
 ************************************************************************/

#include <iostream>
using namespace std;

long long quick_mode(long long a, long long b,long long p) {
    long long tmp = a, ans = 1;
    while(b){
        if(b & 1 ) ans = ans * tmp % p;
    }
    return ans % p;
}

int main() {
    long long  a, b;
    cin >> a >> b >> c;
    cout<< quick_mode(a, b, q) << endl;
    return 0;
}
