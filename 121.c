#include<stdio.h>
int  main(){
	char a,b;
	scanf("%c %c",&a,&b);
	if(a=='O'&&b=='Y'){printf("MING");}
	if(a=='Y'&&b=='H'){printf("MING");}
	if(a=='H'&&b=='O'){printf("MING");}
	if(b=='O'&&a=='Y'){printf("LI");}
	if(b=='Y'&&a=='H'){printf("LI");}
	if(b=='H'&&a=='O'){printf("LI");}
	if(a=='O'&&b=='O'){printf("TIE");}
	if(a=='Y'&&b=='Y'){printf("TIE");}
	if(a=='H'&&b=='H'){printf("TIE");}

}

