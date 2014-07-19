//============================================================================
// Name        : aoj0203.cpp
// Title       : A New Plan of Aizu Ski Resort (会津山スキー場の新企画)
// Author      : mizo0203
// Status      : Accepted
// Date        : Wed May 30 15:25:20
// Copyright   : copyright free
// Description : 動的計画法
//============================================================================

#include <stdio.h>
#include <algorithm>

using namespace std;

int x, y;
int c[17][17];  // 最大15+2

int dp[17][17]; // 動的計画法の計算用

bool input() {
  int i, j;
  scanf("%d %d", &x, &y);
  if (!x && !y) return false; // x = 0 かつ y = 0 なら終了
  fill(c[0], c[0] + 17 * 17, 1); // 配列cを1(木)で初期化
  for (i = 1; i <= y; i++) {
    for (j = 1; j <= x; j++) {
      scanf("%d", &c[i][j]);
    }
  }

  return true;
}

void manage() {
  int i, j, output = 0;

  fill(dp[0], dp[0] + 17 * 17, 0); // 計算用配列を初期化
  for (i = 1; i <= x; i++) {
    if (c[y][i] != 1) dp[y][i] = 1;
  }
  for (i = 1; i <= x; i++) {
    if (c[y - 1][i] == 2) dp[y - 1][i] = 1;
  }

  for (i = y; i > 0; i--) {
    for (j = x; j > 0; j--) {
      if (dp[i][j]) {
        if (c[i][j] == 0) {
          if (c[i - 1][j - 1] == 0) dp[i - 1][j - 1] += dp[i][j];
          if (c[i - 1][j    ] == 0) dp[i - 1][j    ] += dp[i][j];
          if (c[i - 1][j + 1] == 0) dp[i - 1][j + 1] += dp[i][j];
          if (c[i - 2][j    ] == 2) dp[i - 2][j    ] += dp[i][j];
        } else if (c[i][j] == 2) {
          if (c[i - 1][j] == 0) dp[i - 1][j] += dp[i][j];
          if (c[i - 2][j] == 2) dp[i - 2][j] += dp[i][j];
        }
      }
    }
  }

  for (i = 1; i <= x; i++) {
    output += dp[1][i];
  }
  printf("%d¥n", output);
}


int main() {

  while(input()) {
    manage();
  }

  return 0;
}
