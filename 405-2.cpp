/*************************************************************************
	> File Name: 405-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月18日 星期三 20时02分02秒
 ************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;
};

int n, m, k;
char mmap[3005][3005];
int check[3005][3005], ans;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node> que;

void func(int x0, int y0) {
    for (int i = 0; i < 4; i++) {
        int x = x0 + dir[i][0];
        int y = y0 + dir[i][1];
        if (x == 0 || y == 0 || x > n || y > m) continue;
        if (check[x][y] == 0 && mmap[x0][y0] != mmap[x][y]) {
            ans++;
            check[x][y] = 1;
            que.push({x, y});
            func(x, y);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
            }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j] == 0) {
                ans = 1;
                check[i][j] = 1;
                que.push({i, j});
                func(i, j);
                while (!que.empty()) {
                    node temp = que.front();
                    que.pop();
                    check[temp.x][temp.y] = ans;
                }
                ans = 0;
            }
        }
    }
    for (int i = 0; i < k; i++) { int t1, t2;
        cin >> t1 >> t2;
        cout << check[t1][t2] << endl;
    }
    return 0;
}
