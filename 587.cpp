/*************************************************************************
	> File Name: 587.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时06分44秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main(){
    int n,a,b,c,ans;
    cin >> n >> a >> b >>c;
    if(a < b){
        if(a < c){
            ans = 1;
        }else{
            ans = 3;
        }
    }else{
        if(b < c){
            ans = 2;
        }else{
            ans = 3;
        }
    }
    switch(ans){
        case 1:{
            if(b > c){
                cout << "0"<< endl;
            }else{
                cout << "1" << endl;
            }
        }break;
        case 2:{
            if(a > c){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }
        }break;
        case 3:{
            if(a > b){
                cout << "0" << endl;
            }else{
                cout << "1" << endl;
            }
        }break;
    }
    return 0;
}
