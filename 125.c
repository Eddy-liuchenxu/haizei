#include<stdio.h>
int main(){
	int h,m,s,t,h1,m1,s1;
	scanf("%d%d%d%d\n",&h,&m,&s,&t);
	h1=h+t/3600;
	m1=m+t/60%60;
	s1=s+t-t/60-t/60%60;
	if(s1>=60){
	s1=s1-60;
	m1=m1+1;
	if(m1>=60){
	m1=m1-60;
	h1=h1+1;}}
	h1=h1%24;
	if(h1>=0&&h1<=11){
	printf("%d:%d:%dam\n\%%.2lf",h1,m1,s1,t/86400.0*100);}
	if(h1>12&&h1<=23){
	printf("%d:%d:%dpm\n\%%.2lf",h1%12,m1,s1,t);}
	if(h1==12){
	printf("%d:%d:%dpm\n\%%.2lf",12,m1,s1,t);}
}
