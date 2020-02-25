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
            int right = 1, left = len, mid;
            while(right <= left) {
                mid = (right + left ) >> 1;
                if(num[i] > f[mid]) right = mid + 1;
                else left = mid - 1;
            }
            f[right] = num[i];
        }
    }
    cout << len <<endl;

}
