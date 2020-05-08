/*************************************************************************
> File Name: 558.cpp
> Author: 
> Mail: 
> Created Time: 2020年05月08日 星期五 23时49分17秒
************************************************************************/

#include <iostream>
using namespace std;

int w[105],v[105];
int ans[1005];
int main(){
    int t,m;
    cin >> t >> m;
    for(int i = 1; i <= m; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = t; j != 0; j-- ){
            if(j < w[i]){
                break;
            }else{
                ans[j] = max(ans[j],ans[j-w[i]] + v[i]);
            }
        }
    }
    cout << ans[t];
    return 0;
}
