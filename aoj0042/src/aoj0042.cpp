//============================================================================
// Name        : aoj0042.cpp
// Title       : A Thief
// Author      : mizo0203
// Status      : Accepted
// Date        : Tue Nov 20 18:24:31
// Copyright   : copyright free
// Description : 動的計画法(DP)によるナップサック問題 + 重さの総和
//============================================================================

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 1000  // お宝の総数の最大値
#define MAX_W 10000 // お宝の重さの最大値
using namespace std;

int W; // 風呂敷の耐えられる重さ
int N; // お宝の数

int w[MAX_N]; // お宝の重さ
int v[MAX_N]; // お宝の価値

// DP テーブル
// long int 型だと Memory Limit Exceeded になる
short int dp[MAX_N + 1][MAX_W + 1];

// 入力
bool input() {
  scanf("%d", &W);
  if(!W) return false;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    // コンマで区切られた入力には，以下の scanf 関数を書く
    scanf("%d,%d", &v[i], &w[i]);
  }
  return true;
}

// 動的計画法(DP)
// 『プログラミングコンテストチャレンジブック』を参考
void solve() {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j < w[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = (short)max((int)dp[i][j], dp[i][j - w[i]] + v[i]);
      }
    }
  }

}

int main() {

  int cnt = 0;

  while (input()) {
    solve(); // 動的計画法(DP)

    // 重さの総和を探索
    int i;
    for (i = W; i >= 0; i--) {
      if (dp[N][W] != dp[N][i]) break;
    }

    // 出力
    printf("Case %d:\n", ++cnt);
    printf("%d\n", dp[N][W]); // お宝の価値総和
    printf("%d\n", i + 1);    // お宝の重さの総和
  }

  return 0;
}
