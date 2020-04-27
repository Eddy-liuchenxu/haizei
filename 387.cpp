/*************************************************************************
	> File Name: 386.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月10日 星期五 15时17分25秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int m,n;
int y[100005];

struct gua{
    int num; //数目
    int w;   //编号
};

struct gua x[100005];

int binary_sort(int t){
    int l = 0,r = m - 1;
    if(y[t] > x[m-1].num){
        return 0;
    }
    while(l != r){
        int mid = (r + l)/2;
        if(x[mid].num < y[t]){
            l = mid + 1;
        }else if(x[mid].num >= y[t]){
            r = mid;
        }
    }
    return x[l].w;
}

bool cmp(gua a, gua b){
    return a.num < b.num;
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        cin >> x[i].num;
        x[i].w = i + 1;

    }
    sort(x, x + m,cmp);
    for(int i = 0; i < n; i++){
        cin >> y[i];
    }
    for(int i = 0; i < n; i++){
        int ans = binary_sort(i);
        cout << ans << endl;
    }
    return 0;
}

