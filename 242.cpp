/*************************************************************************
	> File Name: 242.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月21日 星期三 15时30分05秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 100000
int num[max_n + 5] = {0};
int main() {
    int n, m,sum = 0;
    double ans, fin = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for(int i = m ; i <= n; i++) {
        for(int temp = 1; temp <= n - m + 1;temp++) {
            sum = 0;
            for(int j = temp; j <= temp +  i; j++) {
                sum += num[j];
        }
             ans =(double)sum / (double)i;
                if(ans > fin) {
                    fin = ans;
                }
        }
    }
    cout << int(fin * 1000) << endl;

}
