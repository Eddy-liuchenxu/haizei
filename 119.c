#include<stdio.h>
int main(){
int y,m,d;
scanf("%d%d%d",&y,&m,&d);

if(d==1){
if(y%400==0||(y%100!=0&&y%4==0)){

if(m==3){
printf("%d %d %d\n%d %d %d\n",y,m-1,29,y,m,d+1);}
else if(m==5||m==7||m==10||m==12)
{
printf("%d %d %d\n%d %d %d",y,m-1,30,y,m,d+1);}
else if(m==2||m==4||m==6||m==8||m==9||m==11){
printf("%d %d %d\n%d %d %d\n",y,m-1,31,y,m,d+1);}
else if(m==1){printf("%d %d %d\n%d %d %d\n",y-1,12,31,y,m,d+1);}
}
else {
if(m==3){
printf("%d %d %d\n%d %d %d\n",y,m-1,28,y,m,d+1);}
else if(m==5||m==7||m==10||m==12)
{
printf("%d %d %d\n%d %d %d",y,m-1,30,y,m,d+1);}
else if(m==2||m==4||m==6||m==8||m==9||m==11){
printf("%d %d %d\n%d %d %d\n",y,m-1,31,y,m,d+1);}
else if(m==1){printf("%d %d %d\n%d %d %d\n",y-1,12,31,y,m,d+1);}
}}
else if(d==31||d==30||d==29||d==28){
if(y%400==0||(y%100!=0&&y%4==0)){
if(m==2&&d==29){
printf("%d %d %d\n%d %d %d\n",y,m,28,y,m+1,1);}
else if(m==2&&d==28){
printf("%d %d %d\n%d %d %d\n",y,m,d-1,y,m,d+1);}
else if(m==3||m==5||m==7||m==8||m==10||m==1)
{
printf("%d %d %d\n%d %d %d",y,m,30,y,m+1,1);}
else if(m==4||m==6||m==9||m==11){
printf("%d %d %d\n%d %d %d\n",y,m,29,y,m+1,1);}
else if(m==12){printf("%d %d %d\n%d %d %d\n",y,12,30,y+1,1,1);}
}
else{
if(m==2){
printf("%d %d %d\n%d %d %d\n",y,m,27,y,m+1,1);}
else if(m==3||m==5||m==7||m==8||m==10||m==1)
{
printf("%d %d %d\n%d %d %d",y,m,30,y,m+1,1);}
else if(m==4||m==6||m==9||m==11){
printf("%d %d %d\n%d %d %d\n",y,m,29,y,m+1,1);}
else if(m==12){printf("%d %d %d\n%d %d %d\n",y,12,30,y+1,1,1);}
}}
else {printf("%d %d %d\n%d %d %d\n",y,m,d-1,y,m,d+1);}}
