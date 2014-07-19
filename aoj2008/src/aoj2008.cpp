//============================================================================
// Name        : aoj2008.cpp
// Title       : Dragon Fantasy
// Author      : mizo0203
// Status      : Accepted
// Date        : 2012/04/17 18:28:54
// Copyright   : copyright free
// Description : 深さ優先探索(DFS)による全探索 + 枝刈り
//============================================================================

#include <stdio.h>
#include <math.h>

int n;
int hx, hy, dx, dy;
int cx[20], cy[20];
double cdis[20]; // 魔王とクリスタルの距離

// 入力
bool input() {
  int i;

  scanf("%d %d %d %d %d", &n, &hx, &hy, &dx, &dy);
  if (!n && !hx && !hy && !dx && !dy)
    return false;
  for (i = 0; i < n; i++) {
    scanf("%d %d", &cx[i], &cy[i]);
    cdis[i] = hypot(dx - cx[i], dy - cy[i]); // 魔王とクリスタルの距離を算出
  }

  return true;
}

// 再帰関数
// bit:クリスタルの回収状況 sum:勇者の総移動距離 x,y:勇者の現在地
bool recursive(long bit, double sum, int x, int y) {
  int i;
  double minD = 2000000.0; // 魔王と魔王に最も近いクリスタルの距離
  double maxH = -1.0; // 勇者の総移動距離+勇者と魔王に最も近いクリスタルの距離

  /* 【探索終了】
   * 全てのbitが立つとクリスタルの収集が完了したため
   * 探索を終了する
   */
  for (i = 0; i < n; i++)
    if (~bit & 1 << i)
      break;
  if (i == n) // クリスタルの回収完了
    return true; // 探索終了

  /* 【枝刈り】
   * 「勇者の総移動距離+勇者と魔王に最も近いクリスタルの距離」が
   * 「魔王と魔王に最も近いクリスタルの距離」以上長いならば
   * 勇者は魔王に最も近いクリスタルが回収不能のため
   * それ以上の探索をしない
   */
  for (i = 0; i < n; i++) { // 魔王に最も近いクリスタルを探索
    if (bit & 1 << i) // 回収済みのクリスタルはスルー
      continue;
    if (minD > cdis[i]) {
      minD = cdis[i];
      maxH = hypot(x - cx[i], y - cy[i]) + sum;
    }
  }
  if (maxH >= minD) // 枝刈り発生
    return false;

  /* 【深さ優先探索】
   * 未回収のクリスタルを回収する
   * 全ての順列を試みる
   */
  for (i = 0; i < n; i++) {
    if (bit & 1 << i) // 回収済みのクリスタルはスルー
      continue;
    if (recursive(bit | 1 << i, sum + hypot(x - cx[i], y - cy[i]), cx[i],
        cy[i]))
      return true; // 回収完了したらならば探索終了
  }

  return false;
}

int main() {

  while (input()) { // 入力
    if (recursive(0, 0.0, hx, hy)) { // 再帰関数
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
