/*************************************************************************
	> File Name: 192.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 18时13分29秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define EPSILON 1e-5
int a;
double left = 0, right = 30, mid;

double f(double x) {
    return x * exp(x) - a; 
}

double half(int a) {
    while(left <= right){
        mid = (left + right) / 2;
        if(fabs(f(mid)) <= EPSILON) return mid;
        if(f(mid) * f(left) < 0) {
            right = mid;}else{
            left = mid;
        }
    }
    
}

int main() {
    scanf("%d", &a);
    printf("%.4lf", half(a));
}
