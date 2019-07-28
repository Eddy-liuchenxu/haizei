#include <stdio.h>

int main() {
	char a[100],i=0,j=0;
	while(scanf("%s", a) != EOF) {
		getchar();
		for(i=0;i<100;i++)
		if(a[i] == 'A' ){
		j++;
		}
		i++;
		printf("%d", j);
		}

}
