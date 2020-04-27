/*************************************************************************
	> File Name: 535-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月06日 星期一 20时45分11秒
 ************************************************************************/

#include <iostream>
using namespace std;

int h,w,tx,ty;
char mmap[55][55] = {0};
int ans = 1;
int dir[4][2] = {
    0,1,
    1,0,
    0,-1,
    -1,0
};


void func(int tx,int ty){
    if(tx < 0 ||tx >= w || ty < 0 || ty >= h){
        return ;
    }
    for(int i = 0; i < 4; i++){
        int x = tx + dir[i][0];
        int y = ty + dir[i][1];
        if(mmap[x][y] == '.'){
            mmap[x][y] = 0;
            ans++;
            func(x,y);
        }
    }

}


int main(){
    cin >> h >>w;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            cin >> mmap[i][j];
            if(mmap[i][j] == '@'){
                tx = i;
                ty = j;
            }
        }
    }
    func(tx,ty);
    cout << ans << endl;
    return 0;
}
