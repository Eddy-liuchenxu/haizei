/*************************************************************************
	> File Name: 44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月17日 星期六 18时23分14秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
#define max_n 10000000

int num[max_n + 5] = {0};
int f[max_n + 5] = {1}; 

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >>num[i];
    }
    for(int i = 1; i <= max_n; i++) {
        f[i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(num[i] > num[j]) {
                f[i] = max(f[i] , f[j] + 1);
            }
        }
    }
    sort(f,f + max_n,greater<int>());
    cout << f[0] << endl;
    return 0;
}
