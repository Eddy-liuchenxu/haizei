/*************************************************************************
> File Name: 390.cpp
> Author: 
> Mail: 
> Created Time: 2020年04月27日 星期一 16时57分25秒
************************************************************************/

#include <iostream>
using namespace std;

int num[100005];
int n,m,max_num = 0;
int cut(int mid){
    int ans = 0;
    for(int j = 0; j < n; j++){
        ans += (num[j] / mid);
    }
    return ans;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        max_num = max(num[i],max_num);
    }

    int l= 1, r= max_num;
    while(l != r){
        int mid = l + ((r - l + 1)>>1);
        if(cut(mid) <  m){
            r = mid - 1;
        }else{
            l = mid;
        }
    }
    cout << l << endl;
}
