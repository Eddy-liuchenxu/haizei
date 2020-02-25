/*************************************************************************
	> File Name: 226.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 14时54分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef long long ll;

ll my_pow(ll a, ll b, ll p) {
    ll res = 1; //结果
    while(b) { // 当b不是零时
        if(b & 1) res = (res * a) % p; //选择
        a = (a * a) % p;
        b  >>=  1;
    }
    return res % p;
}

int main() {
    ll a, b, c;
    while(cin >> a >> b >> c) cout << my_pow(a, b, c) << endl;
    return 0;
}
