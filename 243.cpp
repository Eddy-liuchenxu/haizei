/*************************************************************************
	> File Name: 243.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月21日 星期三 18时23分13秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<inttypes.h>
#define max_n 200000
long long s[max_n + 5][4];
long long w[max_n + 5][max_n + 5];
long long sum[max_n + 5][max_n + 5];

 long long t, n, max_e = 0, min_s = INT64_MAX; 
int func(long long x) {
    long long left = 1, right = INT64_MAX, mid;
    while(left < right) {
        mid = (left + right) / 2;
        if( % 2 == 0) left = mid + 1;
        else right = mid;
    }
    if(right == left) {
        return right;
    }else{
        return -1;
    }
}

int main() {
    memset(sum, 0, sizeof(sum));
    memset(w, 0, sizeof(w));
    memset(s, 0, sizeof(s));
    scanf("%lld", &t);
    for(int i = 1; i <= t; i++) {
        scanf("%lld", &n);
        for(int j = 1; j <= n; j++) {
            
            for(int x = 1; x <= 3; x++) {
                scanf("%lld", &s[j][x]);
            }
            for(int a = s[j][1]; a <= s[j][2]; a += s[j][3]) {
                w[i][a] += 1; 
            }
            if(max_e < s[j][2]) {
                max_e = s[j][2]; 
            }
            if(min_s > s[j][1]) {
                min_s = s[j][1];
            }
        }
        for(int j = min_s; j <= max_e; j++) {
            sum[i][j] = sum[i][j - 1] + w[i][j];
        }
        for(int j = min_s; j <= max_e; j++) {
        if(func(sum[i][j]) > 0) {
            printf("%d %lld", j,w[i][j]);
        }else{
            printf("Poor QIN Teng:(");
        }
        }
        
    

    }

    return 0;
    
}
