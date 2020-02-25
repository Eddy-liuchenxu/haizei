/*************************************************************************
	> File Name: 59.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 17时52分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>

#define Plog(frm, arg...) { \
    printf("[ %s : %d -> output ] " frm "\n", __func__, __LINE__, ##arg); \
    fflush(stdout); \
}

int sum(int n, ...);

void haizei_test() {
    Plog("%d", sum(2, 1, 3));
    Plog("%d", sum(2, 2, 4));
    Plog("%d", sum(10, 5, 3, 6, 9, 10, 11, 1998, 10287, 987, 18713));
    Plog("%d", sum(3, 1, 9, 8, 7, 4));
}

int main() {
    haizei_test();
    return 0;
}

int sum(int n, ...) {
  int i = 0;
  int ans = 0;
  va_list argptr;
  va_start( argptr, n );        
  for ( i = 0; i < n; ++i )
    ans += va_arg( argptr, int );
  va_end( argptr );
  return ans;
}

