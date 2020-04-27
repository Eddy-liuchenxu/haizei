/*************************************************************************
	> File Name: 389.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月27日 星期一 19时09分29秒
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;
int m, n, max_num;
int num[100005];

int func(int mid){
    int cnt = 1;
    int num_x = 0;
    for(int i = 1; i < m; i++){
        if(num[i] - num[num_x] >= mid){
            cnt++;
            num_x = i;
        }
        
    }
    return cnt;
}

int main(){
    cin >> m >> n;
    for(int i= 0; i < m; i++){
        cin >> num[i];
        max_num = max(max_num,num[i]);
    }
    sort(num,num+m);
    int l = 1, r = max_num;
    while(l != r){
        int mid = (l + ((r - l + 1)>>1));
        if(func(mid) < n){
            r = mid - 1;
        }else{
            l = mid;
        }
    }
    cout << l << endl;
    return 0;

}
