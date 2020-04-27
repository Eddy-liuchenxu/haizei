/*************************************************************************
	> File Name: 236-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 19时41分56秒
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, num[15], cnt;

void func(int s, int left) {
    if(left == 0) {
        for(int i = 0; i < cnt; i++) {
            if(i ) cout << " ";
            cout << num[i];
        }
        cout<< endl;
        return ;
    }
    for(int i = s; i <= n; i++) {
        num[cnt] = i;
        cnt++;
        func(i + 1, left-1);
        cnt--;
    }
}

int main() {
    cin >> n >> m;
    func(1,m);
    return 0;
}
