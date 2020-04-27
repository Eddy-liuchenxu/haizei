/*************************************************************************
	> File Name: 83.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 20时10分54秒
 ************************************************************************/

#include <iostream>
using namespace std;
int num[]
int func(int s, int left_num, int left_cnt) {
    if(left_cnt == 0) {
        if(left_num == 0){
           p();
            return 1;
        
        }
        return 0;
    }
    int ans = 0;
    for(int i = s; i <= left_num; i++) {
        num[cnt] = i;
        cnt++;
        ans +=func(i ,left_num - i, left_cnt - 1);
        cnt--;
    }
    return ans;
}


int main() {
    int n,m;
    cin >>  n >> m;
    cout << func(1,n,m) << endl;
    return 0;
}
