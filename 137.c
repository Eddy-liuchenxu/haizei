#include<stdio.h>
int main() {
	int n,j,i,s,a=0;
	char z[40] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		s=i;
		for(j=i;j<n;j++) {
			printf("%c",z[a+j-i]);
		}
		a=a+n-i+1;
		printf("%c\n",z[a-1]);
	}	
}
