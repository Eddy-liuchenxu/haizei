#include<stdio.h>
int main() {
	int x,y,m,d,m1,y1,d1,i;
	scanf("%d\n%d%d%d",&x,&y,&m,&d);
	while(x) {
		if(m==1||m==3||m==5||m==7||m==8||m==10) {
			if(d+x<=31){
			printf("%d %d %d\n",y,m,d+x);
			x=0;
			} else {
			x = x-31+d;
			m = m+1;
			d=0;
			}}
		if(m==12){
                     if(d+x<=31){
			     
                        printf("%d %d %d\n",y,m,d+x);
			x=0;
                        } else {
                        x = x-31+d;
                        m = 1;
			y =y+1;
			d=0;}
                  }
		if((y%4==0&&y%100!=0)||y%400==0){
			if(m==2){
			if(d+x<=29){
				
			printf("%d %d %d\n",y,m,d+x);
			x=0;}else{
			x = x-29+d;
			m = m+1;
			d=0;}}}
		else if(m==2) {
		if(d+x<=28){
			
		printf("%d %d %d\n",y,m,d+x);
		x=0;}else{
		x= x-28+d;
		m = m+1;
		d=0;}}
                if(m==4||m==6||m==9||m==11) {
                        if(d+x<=30){
				
                        printf("%d %d %d\n",y,m,d+x);
			x=0;
                        } else {
                        x = x-30+d;
                        m = m+1;
			d=0;
                        }}



	}
}

