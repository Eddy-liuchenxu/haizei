#include<stdio.h>
int main()
{
int y,m,d;
scanf("%d%d%d",&y,&m,&d);
if(y>0&&m<=12&&m>0){
if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
{if(d<=31&&d>0){printf("YES");}
else{printf("NO");}}
if(m==4||m==6||m==9||m==11){
if(d<=30&&d>0){printf("YES");}
else{printf("NO");}}
if(y%400==0||(y%100!=0&&y%4==0))
{if(m==2){if(d<=29&&d>0){printf("YES");}
else{printf("NO");}}}
else if(m==2){if(d<=28&&d>0){printf("YES");}
else{printf("NO");}}
}else{printf("NO");} }
