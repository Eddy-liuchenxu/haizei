/*************************************************************************
	> File Name: 227.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月27日 星期二 16时33分17秒
 ************************************************************************/

#include<iostream>
#include<cinttypes>
using namespace std;

int main() {
    int64_t a, b, p;
    int64_t res = 0, n = 1;
    cin >> a >> b >> p;
    while(b) {
        if(b & 1) {
            res = (res + a) % p;
        }
        a = (long long)a * 2 % p;
        b = b >> 1;
    }
    cout << res % p;
}
