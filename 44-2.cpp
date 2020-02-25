/*************************************************************************
	> File Name: 44-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月17日 星期六 21时19分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 1000000

int num[max_n + 5] = {0};
int f[max_n + 5] = {0};

int half_path(int a, int right) {
    int left = 1, mid;
    mid = (left + right) / 2;
    while(left <= right) {
        if(a > f[mid] && a <= f[mid + 1]) return mid;
        else if(a > f[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main() {
    int n, len = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    f[1] = num[1];
    for(int i = 2; i <= n; i++) {
        if(num[i] > f[len]) f[++len] = num[i];
        else {
            f[half_path(num[i], len) + 1] = num[i];
        }
    }
    cout << len <<endl;

}
