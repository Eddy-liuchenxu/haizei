/*************************************************************************
	> File Name: 235-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 20时03分50秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
using namespace std;
// 当前边的编号，　最大值，　层数，数组存值
void output(int ind,int n,int k, int *buff) {
    if (ind == n) {
        return;
    }
    for (int i = ind+1; i <= n; i++) {
        buff[k] = i;
        for(int j = 0; j <= k;j++) {
            if (j != 0) {
                cout << " ";
            }
            cout << buff[j];
        }
        cout << endl;
        output(i, n, k + 1, buff);
    }
    return ;
}
 
int a[25];
int main() {
 
    int n;
    cin >> n;
    output(0,n,0,a);
    return 0;
}
