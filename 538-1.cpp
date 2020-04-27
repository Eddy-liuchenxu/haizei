/*************************************************************************
	> File Name: 538-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月07日 星期二 00时55分29秒
 ************************************************************************/

#include <iostream>
using namespace std;
int n;
int num[25][25],check[25],flag;

void func(int s){
    if(flag == 1){
        cout << '-';
    }    
    flag = 1;
    cout << s;
    for(int i = 1; i <= n; i++){
        if(num[s][i] == 1 && check[i] == 0){
            check[i] = 1;
            func(i);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n ; j++){
            cin >> num[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(check[i] == 0){
            check[i] = 1;
            func(i);
        }
    }
    return 0;
}
