//============================================================================
// Name        : aoj0110.cpp
// Title       : Alphametic
// Author      : mizo0203
// Status      : Accepted
// Date        : Thu Oct 04 23:47:48
// Copyright   : copyright free
// Description : 多倍長整数の加算, 全探査
//============================================================================

#include <stdio.h>
#include <string.h>
#ifndef NULL
#define NULL ((void *) 0)
#endif
using namespace std;

char str[127], a[127], b[127], c[127];
int zero, sum;

bool input() {
  if (gets(str) == NULL)
    return false;
  return true;
}

int main() {
  int i, j;
  int s, g;

  while (input()) {
    zero = 0;
    s = 0;
    g = strchr(str, '+') - str;
    memset(a, 0, sizeof(a));
    for (i = s; i < g; i++) {
      if (str[g - i - 1] != 'X')
        a[i] = str[g - i - 1] - '0';
      else
        a[i] = -1;
    }
    if (i > 1 && a[i - 1] == -1) {
      zero = 1;
    }
    s = g + 1;
    g = strchr(str, '=') - str;
    memset(b, 0, sizeof(b));
    for (i = 0; i < g - s; i++) {
      if (str[g - i - 1] != 'X')
        b[i] = str[g - i - 1] - '0';
      else
        b[i] = -1;
    }
    if (i > 1 && b[i - 1] == -1) {
      zero = 1;
    }
    s = g + 1;
    g = strlen(str);
    memset(c, 0, sizeof(c));
    for (i = 0; i < g - s; i++) {
      if (str[g - i - 1] != 'X')
        c[i] = str[g - i - 1] - '0';
      else
        c[i] = -1;
    }
    if (i > 1 && c[i - 1] == -1) {
      zero = 1;
    }
    for (i = zero; i < 10; i++) {
      sum = 0;
      for (j = 0; j < 127; j++) {
        if (a[j] != -1)
          sum += a[j];
        else
          sum += i;
        if (b[j] != -1)
          sum += b[j];
        else
          sum += i;
        if (c[j] != -1) {
          if (sum % 10 != c[j])
            break;
        } else {
          if (sum % 10 != i)
            break;
        }
        sum /= 10;
      }
      if (j == 127) {
        printf("%d\n", i);
        break;
      }
    }
    if (i == 10) {
      printf("NA\n");
    }
  }

  return 0;
}
