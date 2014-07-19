//============================================================================
// Name        : aoj1180.cpp
// Title       : Recurring Decimals (繰り返す10進数)
// Author      : mizo0203
// Status      : Accepted
// Date        : Wed Feb 13 11:14:27
// Copyright   : Your copyright free
// Description : 文字列操作
//============================================================================

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;

int a0, L;

bool input() {
  scanf("%d %d", &a0, &L);
  if (!a0 && !L)
    return false;
  return true;
}

int main() {
  int i, j;
  char a[21][7];
  char b[2][7];

  while (input()) {                  // 入力
    sprintf(a[0], "%0*d", L, a0);    // 文字列へ変換
    //printf("%s\n", a[0]);

    for (i = 1;; i++) {
      strcpy(b[0], a[i - 1]);        // 文字列をコピー
      strcpy(b[1], a[i - 1]);
      sort(b[0], b[0] + L);                 // 昇順へソート
      sort(b[1], b[1] + L, greater<int>()); // 降順へソート
      sprintf(a[i], "%0*d", L, atoi(b[1]) - atoi(b[0])); // 演算
      //printf("%s=%s-%s\n", a[i], b[1], b[0]);

      for (j = 0; j < i; j++) {      // 条件(ai=aj)を満たすか調べる
        if (!strcmp(a[j], a[i])) {
          printf("%d %d %d\n", j, atoi(a[j]), i - j); // 結果を出力
          break;
        }
      }
      if (j != i)
        break;

    }
  }

  return 0;
}
