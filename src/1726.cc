// BOJ 1726
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
#define E 1
#define W 2
#define S 3
#define N 4
typedef struct {
  pp pos;
  pp prev;
  int tim;
} stat;

int getdir(const pp &from, const pp &to) {
  if (from.fi == to.fi)
    return from.se < to.se ? E : W;
  else
    return from.fi < to.fi ? S : N;
}

pp move(const pp &from, const int &dir) {
  pp res = from;
  switch (dir) {
  case E:
    res.se++;
    break;
  case W:
    res.se--;
    break;
  case N:
    res.fi--;
    break;
  case S:
    res.fi++;
    break;
  }
  return res;
}

int counterdir(const int &dir) {
  switch (dir) {
  case E:
    return W;
  case W:
    return E;
  case N:
    return S;
  case S:
    return N;
  }
}

int dircomp(const int &a, const int &b) {
  if (a == E || a == W) {
    if (b == S || b == N)
      return 1;
    else if (a == b)
      return 0;
    else
      return 2;
  } else {
    if (b == E || b == W)
      return 1;
    else if (a == b)
      return 0;
    else
      return 2;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int r, c;
  cin >> r >> c;
  vector<vector<int>> fac(r);
  vector<vector<vector<int>>> bt(r);
  for (int i = 0; i < r; i++) {
    fac[i].resize(c);
    bt[i].resize(c);
    for (int j = 1; j < c; j++)
      bt[i][j].resize(4), cin >> fac[i][j];
  }
  stat start;
  int dir;
  cin >> start.pos.fi >> start.pos.se >> dir;
  start.prev = move(start.pos, counterdir(dir));
  start.tim = 0;

  queue<stat> q;
  q.push(start);
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
  }

  return 0;
}
