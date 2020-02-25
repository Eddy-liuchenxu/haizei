/*************************************************************************
	> File Name: 193.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 20时28分28秒
 ************************************************************************/

#include<stdio.h>

long long n, a[100005],k,s;
int left = 0 , right , mid;
int y(int x){
    return x - k - s;
}

int f(int k,int s) {
    right = n - 1;
    while(left <= right) {
        mid = (left + right) / 2;
        if(y(mid) == 0)  return 1;
        if(y(left) * y(mid) < 0) {
            right = mid - 1;
        }else {
            left = mid + 1;
        }

    }
    return 0;
}

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld",&a[i]);
    }
    scanf("%lld%lld", &k, &s);
    if(!f( k, s)) {
        printf("No");
    }else {
        printf("Yes");
    }

}
