#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, m;
int a;
vector<vector<int>> room;
vector<pair<pp, int>> cctv;
vector<vector<int>> view;
typedef enum { N, E, S, W } polar;

polar nextpolar(polar p) { return (polar)((p + 1) % 4); }

pp operator+(const pp &p1, const pp &p2) {
  return {p1.fi + p2.fi, p1.se + p2.se};
}

bool validpos(pp pos) {
  return (pos.fi >= 0) && (pos.fi < n) && (pos.se >= 0) && (pos.se < m);
}

void goline(pp pos, polar p, bool sgn) {
  pp dp;
  switch (p) {
  case N:
    dp = {-1, 0};
    break;
  case E:
    dp = {0, 1};
    break;
  case W:
    dp = {0, -1};
    break;
  case S:
    dp = {1, 0};
    break;
  }

  for (int i = 0; validpos(pos); i++) {
    if (room[pos.fi][pos.se] == 6)
      break;
    view[pos.fi][pos.se] += (sgn ? 1 : -1);
    pos = pos + dp;
  }
}

void docctv(pp pos, int ctype, polar p, bool sgn) {
  switch (ctype) {
  case 1:
    goline(pos, p, sgn);
    break;
  case 2:
    goline(pos, p, sgn);
    goline(pos, nextpolar(nextpolar(p)), sgn);
    break;
  case 3:
    goline(pos, p, sgn);
    goline(pos, nextpolar(p), sgn);
    break;
  case 4:
    goline(pos, p, sgn);
    goline(pos, nextpolar(p), sgn);
    goline(pos, nextpolar(nextpolar(p)), sgn);
    break;
  case 5:
    goline(pos, N, sgn);
    goline(pos, S, sgn);
    goline(pos, E, sgn);
    goline(pos, W, sgn);
    break;
  }
}

int countsg() {
  int sg = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (view[i][j] == 0 && room[i][j] == 0)
        sg++;
    }
  }
  return sg;
}

int minsg = ~(1 << 31);

void dfs(int depth) {
  polar news[] = {N, E, W, S};
  if (depth == cctv.size())
    minsg = min(minsg, countsg());
  switch (cctv[depth].se) {
  case 1:
  case 3:
  case 4:
    for (auto i : news) {
      docctv(cctv[depth].fi, cctv[depth].se, i, true);
      dfs(depth + 1);
      docctv(cctv[depth].fi, cctv[depth].se, i, false);
    }
    break;
  case 2:
    docctv(cctv[depth].fi, cctv[depth].se, N, true);
    dfs(depth + 1);
    docctv(cctv[depth].fi, cctv[depth].se, N, false);
    docctv(cctv[depth].fi, cctv[depth].se, E, true);
    dfs(depth + 1);
    docctv(cctv[depth].fi, cctv[depth].se, E, false);
    break;
  case 5:
    docctv(cctv[depth].fi, cctv[depth].se, E, true);
    dfs(depth + 1);
    docctv(cctv[depth].fi, cctv[depth].se, E, false);
    break;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m;
  room.resize(n);
  view.resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a;
      room[i].push_back(a);
      if (a == 6)
        view[i].push_back(-1);
      else if (a == 0)
        view[i].push_back(0);
      else
        cctv.push_back({{i, j}, a}), view[i].push_back(-1);
    }
  }
  if (cctv.size())
    dfs(0);
  else
    minsg = (minsg, countsg());
  cout << minsg;

  return 0;
}
