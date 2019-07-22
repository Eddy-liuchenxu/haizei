#include<stdio.h>
int main(){
	int t,h,m,s;
	scanf("%d",&t);
	h=t/3600;	
	m=t%3600/60;
	s=t-3600*h-60*m;
	if(h<12&&h>=0){printf("%02d:%02d:%02d am",h,m,s);}
	if(h>=12&&h<=13){printf("12:%02d:%02d midnoon",m,s);}
	if(h>13){printf("%02d:%02d:%02d pm",h-12,m,s);}
}
