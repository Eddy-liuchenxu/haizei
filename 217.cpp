/*************************************************************************
	> File Name: 217.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 14时11分48秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 100000
int num[max_n + 5] = {0};

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, ans, temp;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    ans = n / 2 + 1;
    temp = n / 2 + 1;
    sort(num + 1, num + 1 + n, cmp);
    printf("%d",num[ n / 2 + 1]);
    while(num[temp] == num[temp + 1]) {
        ans = temp + 1;
        temp++;
    }
    printf(" %d", temp);
}
