/*************************************************************************
	> File Name: 1.define.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月12日 星期四 19时16分26秒
 ************************************************************************/

#include<stdio.h>
#ifdef DUBUG
#define log(frm, arg...) {\
    printf("[%s : %s : %d]", __FILE__,__func__, __LINE__ );\
    printf(frm,##arg);\
    printf("\n");\
}
#else
#define log(frm, arg...)
#endif
#define contact(a,b) a##b

int main() {
    int a = 123;
    int abcdef = 15;
    contact(abc,def) = 23;
    log("%d", abcdef);
    log("%d", a);
    log("hello wrold"); 
    printf("[%s : %s : %d] %d\n", __FILE__, __func__ ,__LINE__,a);
    
    return 0;

}
