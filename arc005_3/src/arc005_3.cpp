//============================================================================
// Name        : arc005_3.cpp
// Title       : 器物損壊！高橋君 ( Search and destroy )
// Author      : mizo0203
// Status      : Accepted
// Date        : 2012/06/30 21:53:59
// Copyright   : copyright free
// Description : 幅優先探索(BFS)による全探索
//============================================================================

#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define MAX_V 100
#define INF 3000000
using namespace std;

struct POINT {
  int x, y, cost;
};

int H, W;
int cnt[500][500];
char c[500][501];
queue<POINT> que;
POINT s, g;

bool input() {
  int i, j;

  scanf("%d %d", &H, &W);
  for (i = 0; i < H; i++) {
    scanf("%s", c[i]);
  }
  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      if (c[i][j] == 's') {
        s.x = j;
        s.y = i;
        s.cost = 0;
      } else if (c[i][j] == 'g') {
        g.x = j;
        g.y = i;
      }
    }
  }
  while (!que.empty())
    ;
  fill(cnt[0], cnt[0] + 500 * 500, 3);

  return true;
}

int main() {
  POINT p, q;
  input();
  que.push(s);
  while (!que.empty()) {
    p = que.front();
    que.pop();
    if (p.x < 0 || W <= p.x || p.y < 0 || H <= p.y)
      continue;
    if (c[p.y][p.x] == '#') {
      q.cost = p.cost + 1;
    } else
      q.cost = p.cost;
    if (cnt[p.y][p.x] > q.cost) {
      cnt[p.y][p.x] = q.cost;
      q.x = p.x + 1;
      q.y = p.y;
      que.push(q);
      q.x = p.x - 1;
      q.y = p.y;
      que.push(q);
      q.x = p.x;
      q.y = p.y + 1;
      que.push(q);
      q.x = p.x;
      q.y = p.y - 1;
      que.push(q);
    }
  }

  if (cnt[g.y][g.x] < 3)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
