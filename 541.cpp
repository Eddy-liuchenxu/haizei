/*************************************************************************
	> File Name: 541.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 19时11分07秒
 ************************************************************************/

#include <iostream>
using namespace std;

int n,mn,atime[2][20][20],ans[2][100000],ans_num[2];

void func(int people,int locate, int cost){
    if(locate == n){
        ans[people][ans[people]] = cost;
        ans_num[people]++;
        return;
    }
    for(int i = locate + 1; i <= n; i++){
        if(atime[people][locate][i]){
            func(peole,i, cost + atime[people][locate][i]);
        }
    }
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        atime[0][a][b] = atime[0][b][a] = c;
        atime[1][a][b] = atime[1][b][a] = d;
    }
    func(0,1,0);
    func()
}
