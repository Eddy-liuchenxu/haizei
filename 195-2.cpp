/*************************************************************************
	> File Name: 195.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月21日 星期三 14时37分04秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 100000
int n, m;
int a[max_n + 5] = {0};
int q[max_n + 5] = {0};
int ans[max_n + 5] = {0};

int func(int w) {
    int left = 1, right = n, mid;
    while( left < right) {
        mid = (left + right + 1) / 2;
        if((a[mid] <= w)) left = mid;
        else right = mid - 1;
    }
    if(left == right) return a[right];
    else return a[1];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int j = 1; j <= m; j++) {
        cin >> q[j];
    }
    for(int j = 1; j <= m; j++) {
        ans[j] = func(q[j]);
    }
    for(int j = 1; j <= m; j++) {
        (j - 1) && cout <<" ";
        cout << ans[j];
        
    }


}
