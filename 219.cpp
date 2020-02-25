/*************************************************************************
	> File Name: 219.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 20时44分27秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 10000

int num[max_n + 5] = {0};

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    sort(num + l1, num + r1 + 1);
    sort(num  + l2, num + r2 + 1, cmp);
    for(int i = 1; i <= n; i++) {
        (i - 1) && cout << " ";
        cout << num[i];
    }
}

