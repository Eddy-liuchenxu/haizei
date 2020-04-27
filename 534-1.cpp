/*************************************************************************
	> File Name: 534-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月06日 星期一 22时46分48秒
 ************************************************************************/

#include <iostream>
using namespace std;
int n,num[25],ans = 0;
int check[1005] = {1};

void func(int s,int sum){
    if(check[sum] == 0){
        check[sum] = 1;
        ans++;
    }
    for(int i = s; i <= n; i++){
        sum += num[i];
        func(i + 1, sum);
        sum -= num[i];
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    func(0,0);
    cout << ans;
}
