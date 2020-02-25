/*************************************************************************
	> File Name: 209.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月28日 星期三 19时52分17秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 100
double num[max_n + 5] = {0};

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    for(int i = 0; i < n; i++) {
        cout << num[i] << endl;
    }
}
