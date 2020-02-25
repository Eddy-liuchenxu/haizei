/*************************************************************************
	> File Name: 119.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月05日 星期四 20时01分34秒
 ************************************************************************/
#include<iostream>
using namespace std;

int day[13] = {0, 31 , 28 , 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Days(int y, int m) {
    return day[m] + (m == 2 && (y  % 400 == 0 || y % 4 == 0 && y % 100))
}

void prev_day(int &y, int &m, int &d) {
    d -= 1;
    if(d == 0) {
        m -= 1;
        if(m == 0) {
            y -= 1, m = 12;
        }
        d = Days(y, m);
    }
    return ;
}

void next_day(int &y, int &m, int &d) {
    d += 1;
    if(d > Days(y,m)) {
        m += 1, d = 1;
        if(m > 12) {
            y += 1, m = 1;
        }
    }
    return;
}
int main() {
    int y, m, d;
    cin >> y >> m >> d;
    prev_day(y, m, d);
    cout << y <<" "<< m <<" "<< d;
    next_day(y, m, d);
    next_day(y, m, d);
    cout << y << " " << m << " " << d <<endl;
    return 0;


}
