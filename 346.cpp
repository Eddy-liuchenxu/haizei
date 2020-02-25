/*************************************************************************
	> File Name: 346.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 12时00分25秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

long long f[55][55];

int n, m;

int func(int i, int j) {
    if(i == n && j == m) return f[i][j];
    int val1 = func(i , j + 1);
    int val2 = func(i + 1, j);
    return val1 > val2 ? val1 : val2 + f[i][j];

}


int main() {
    memset(f, 0, sizeof(f));
    cin >> n >> m;
    for(int j = 0; j <= m; j++) {
        f[n + 1][j] = -1;
    } 
    for(int j = 0; j <= n; j++) {
        f[j][m + 1] = -1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> f[i][j];
        }
    }
    cout << func(1, 1) << endl;
}
