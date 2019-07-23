#include<stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d%d\n%d%d",&a,&b,&c,&d);
	if((a<=c&&b>=d)||(a>=c&&b<=d)){printf("YES");}
	else{printf("NO");}
	}
