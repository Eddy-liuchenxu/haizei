/*************************************************************************
	> File Name: 537.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月07日 星期二 00时16分20秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int L,C;
char num[26];
char ans[20];
int cnt = 0;
int fu,yuan,num2;

int func(int s, int left){
    if(left == 0){
        if(yuan >= 1 && fu >= 2){
            for(int i = 0; i < L; i++){
                cout << ans[i];
            }
        
            cout << endl;
            num2++;
            if(num2 == 25000){
                return -1;
            }
        }
    }
    for(int i = s; i < C; i++){
        ans[cnt++] = num[i];
        int f = 0;
        if(num[i] == 'a' || num[i] == 'e' || num[i] == 'i' || num[i] == 'o' || num[i] == 'u'){
            yuan++;
            f = 1;
        }else{
            fu++;
        }
        if(func(i+1,left-1) == -1){
            return -1;
        }
        if(f == 1){
            yuan--;
        }else{
            fu--;
        }
        cnt--;
    }
    return 0;
}

int main(){
    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> num[i];
    }
    sort(num,num+C);
    func(0,L);
}
