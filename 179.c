/*************************************************************************
	> File Name: 179.c
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 23时28分14秒
 ************************************************************************/
#define EPSILON 1e-7
#include <stdio.h>
#include <math.h>

double f(int p, int q, double left, double right);
double g(int p, int q, double x);

int main() {
    int p, q;
    scanf("%d%d", &p, &q);
    double left = -20, right = 20;
    f(p, q, left, right);
}

double f(int p, int q, double left, double right) {
    double mid;
    while(left <= right){
    mid = (left + right) / 2;
    if(fabs(g(p, q, mid)) <  EPSILON) {
        printf("%.4lf", mid);
        break;
    }
    if(g(p, q, mid) * g(p, q, left) < 0) {
        right = mid ;
    }
    if(g(p, q, mid) * g(p ,q, right) < 0) {
        left = mid ;
    }
    }

}

double g(int p, int q, double x) {
    return p * x + q;
}
