/*************************************************************************
> File Name: 559.cpp
> Author: 
> Mail: 
> Created Time: 2020年04月29日 星期三 18时29分16秒
************************************************************************/

#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct num{

    int s,f;
    double v;
};

bool cmp(struct num a,struct num  b){
    return a.v > b.v;
}
int main(){
    int n,m;
    cin >> m >> n;
    struct num num1[1010];
    for(int i = 0; i < n; i++){
        cin >> num1[i].s>> num1[i].f;
        num1[i].v =  (double) num1[i].s / (double) num1[i].f;
    }

    sort(num1,num1+n,cmp);
    double l = m;
    double sum = 0;
    int j = 0;
    while(l >= num1[j].f){
        l -= num1[j].f;
        sum += num1[j++].s;
    }
    if(l) sum += num1[j].v * l;

    printf("%.3lf",sum);
    return 0;
}
