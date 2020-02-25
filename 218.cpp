/*************************************************************************
	> File Name: 218.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 20时19分53秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 100000

struct stud{
    int number;
    int height;
};

bool cmp (stud a, stud b) {
    return  a.height <  b.height;
}

int main() {
    int n;
    struct stud  num[100000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i].height;
        num[i].number = i + 1;
    }
    
    stable_sort(num,(num + n),cmp);
    for(int i = 0; i < n; i++) {
        i && cout << " ";
        cout << num[i].number;
    }
}

