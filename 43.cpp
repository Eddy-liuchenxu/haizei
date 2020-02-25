/*************************************************************************
	> File Name: 43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 19时27分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 1000

int num[max_n + 5][max_n + 5] = {0};

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            num[i][j] += max(num[i + 1][j] ,num[i + 1][j + 1]);
        }
    }
    cout << num[0][0] << endl;
}
