/*************************************************************************
	> File Name: 80-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月07日 星期二 10时37分54秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

char mmap[505][505];
int n,m,sx,sy;
int dir[4][2]={
    0,1,
    1,0,
    -1,0,
    0,-1
};
struct Node{
    int x,y,cnt;
};
queue<Node> que;
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == 's'){
                Node node;
                node.x= i;
                node.y = j;
                node.cnt = 0;
                que.push(node);
            }
        }
    }
    while(!que.empty()){
        Node temp = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int tx = temp.x + dir[i][0];
            int ty = temp.y + dir[i][1];
            if(tx < 0 || ty < 0 || tx >= n || ty >= m){
                continue;
            }
            if(mmap[tx][ty] == 'g'){
                cout << temp.cnt + 1 << endl;
                return 0;
            }
            if(mmap[tx][ty] == '.'){
                mmap[tx][ty] = 0;
                que.push({tx,ty,temp.cnt + 1});
            }
        }

    }
    cout << "No" << endl;
    return 0;
}

