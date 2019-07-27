#include<stdio.h>

int prime(int i) {
	int j;
	for(j = 2;j * j <= i;j++){
	if(i%j == 0) return 0;
	}
	return 1;
}

int pal(int i) {
	int i1,w,q,h,s,g;
	w = i / 10000;
	q = i / 1000 % 10;
	h = i / 100 % 10;
	s = i /10 % 10;
	g = i %10;
	i1 = g * 10000 + s * 1000 + h *100 + q * 10 + w;
	if(i1 == i) return 1;
	return 0;
}


int main () {
	int a,b,flag = 0,i;
	scanf ("%d%d",&a,&b);
	for (i = a;i <= b;i++){
        if(!( prime(i) && pal(i))) continue;
	flag && printf(" ");
	flag++;
	printf("%d",i);
	}
}
