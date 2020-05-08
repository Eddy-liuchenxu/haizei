/*************************************************************************
	> File Name: 589.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时48分09秒
 ************************************************************************/

#include <iostream>
using namespace std;

int func(int a,int b){
    if(b == 0) return a;
    return func(b,a%b);
}

int main(){
    int n,k,id;
    cin >> n >> k >> id;
    int num = func(n,k);
    cout << k/num << "/"<< n/num;
}
