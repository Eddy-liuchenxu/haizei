/*************************************************************************
	> File Name: 560.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 19时00分07秒
 ************************************************************************/
#include<algorithm>
#include <iostream>
using namespace std;

struct num{
    int v,p;
    int sum;
};

bool cmp(num a, num b){
    return a.sum > b.sum;
}
int main(){
    int n,m;
    num num1[30];
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> num1[i].v >> num1[i].p;
        num1[i].sum = num1[i].v * num1[i].p;
    }
    sort(num1,num1+m,cmp);
    return 0;
}
