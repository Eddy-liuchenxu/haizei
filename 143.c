#include <stdio.h>
#include <math.h>
int div(int i){
	if(i % 6 == 0){
	return 1;
	}else{
	return 0;}
}
int pri(int i){
	int k,j;
	k = i / 100;
	for (j = 2;j <= sqrt(k);j++){
		if(k % j == 0) {
		return 0;
		}
	}
	return 1;

}
int squre(int i){
	int k,j;
	k = i % 100;
	for(j = 1;j < k;j++){
		if(j*j == k)return 1;
	}
	return 0;
}




int main () {
	int a,b,i,flag=0;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++){
	if(!(div(i)&&pri(i)&&squre(i)))continue;
	flag && printf(" ");
	flag++;
	printf("%d",i);

	}
	printf("\n%d",flag);
	

}
