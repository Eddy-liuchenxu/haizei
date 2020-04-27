/*************************************************************************
	> File Name: 397.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月18日 星期三 18时28分26秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node{
    int x,int y;
};

int n,m,k, ans = 1,temp,sx,sy;
char mmap[3005][3005];
int dir[4][2] = {0,1,1,0,0,-1,-1,0};
int check[3005][3005];
queue<node> que;
void func(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(tx < 1 || ty < 1 || tx > n ||  ty > m) continue;
        if(mmap[tx][ty] != mmap[x][y] && check[tx][ty] == 0) {
            ans++;
            check[tx][ty] = 1;

            func(tx,ty);
        }

    }
}

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(check[i][j] == 0) {
                check[i][j] = 1;
                que.push({i,j});
                func(i,j);
                while(!que.empty()){
                    node temp
                }
            }
        }

    }
    for(int i = 1; i < k; i++) {
        
        cin >> sx >> sy;
        memset()
        check[sx][sy] = 1;
        func(sx,sy);
        cout << ans << endl;
    }
    cin >> sx >> sy;
    check[sx][sy] = 1;
    func(sx,sy);
    cout << ans << endl;
}
