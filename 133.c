#include<stdio.h>
int main() {
    int n,i,j;
    scanf("%d", &n);
    for(i=1;i<=n;i++) {
        for(j=i;j<n;j++)  {
            printf("%d*%d=%d\t",i,j,i*j);
        }
        printf("%d*%d=%d\n",i,n,i*n);
    }
}
