/*************************************************************************
	> File Name: 40.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 20时02分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

int  f[505][1000] = {{1, 0},{1, 0},{1,1},{1,1}};

int main() {
    int n;
    cin >> n;
    for(int i = 4; i <= n; i++) {
        for(int j = 1; j <= f[0][0]; j++) {
            f[i][j] = f[i - 2][j] + f[i - 3][j];
        }
        for (int k = 1; k <= f[0][0]; k++) {
             if(f[i][k] < 10) continue;
             f[i][k + 1] += f[i][k] / 10; 
             f[i][k] = f[i][k] % 10;
             f[0][0] += (k == f[0][0]);
        }
    }
    for(int i = f[0][0]; i >= 1; i--){
    cout << f[n][i];
    }
    return 0;
}
