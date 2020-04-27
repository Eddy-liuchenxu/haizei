/*************************************************************************
	> File Name: 235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 19时06分40秒
 ************************************************************************/

#include <iostream>
using namespace std;

int num[15],cnt,n;

void p() {
    for(int i = 0; i < cnt; i++) {
        if(i) cout << " ";
        cout <<num[i];
    }
    cout <<endl;
}

void func(int s ) {
    for(int i = s; i <= n; i++) {
        num[cnt] = i;
        cnt++;
        p();
        func(i + 1);
        cnt--;
    }
}
int main() {
    cin >> n;
    func(1);
    return 0;
}
