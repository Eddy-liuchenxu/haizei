/*************************************************************************
	> File Name: 54-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 16时42分29秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_N 100000
int main() {
  int  n;
  while (scanf("%d", &n) != EOF) {
    int num[MAX_N + 5] = {1, 1};
    int sum[MAX_N + 5] = {1, 1};
    for (int i = n; i > 0; --i) {
      for (int j = num[0]; j  > 0; --j) {
        num[j] *= i;
      }
      for (int i = 1; i <= num[0]; ++i) {
        if (num[i] < 10) continue;
        num[i + 1] += num[i] / 10;
        num[i] %= 10;
        num[0] += (i == num[0]);
      }
    }
    for (int i = num[0]; i > 0; --i) {
        if (num[i] != 0) {
          for (int j = sum[0]; j  > 0; --j) {
            sum[j] *= num[i];
          }
          for (int i = 1; i <= sum[0]; ++i) {
            if (sum[i] < 10) continue;
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
            sum[0] += (i == sum[0]);
          }
        }
      }
    for (int i = sum[0]; i > 0; --i)
        printf("%d", sum[i]);
    printf("\n");
  }  
  return 0;
}
