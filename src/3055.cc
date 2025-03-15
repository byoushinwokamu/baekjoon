// BOJ 3055
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

int r, c;
vector<string> v;

const pp dp[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pp operator+(const pp &a, const pp &b) { return {a.fi + b.fi, a.se + b.se}; }
bool valpos(const pp &a) {
  return a.fi >= 0 && a.fi < r && a.se >= 0 && a.se < c;
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> r >> c;
  v.resize(r);

  queue<pair<pp, int>> qb;
  queue<pair<pp, int>> qw;
  vector<vector<bool>> vis(r, vector<bool>(c));
  pp dest;
  for (int i = 0; i < r; i++) {
    cin >> v[i];
    for (int j = 0; j < c; j++)
      switch (v[i][j]) {
      case 'S':
        qb.push({{i, j}, 0});
        vis[i][j] = true;
        break;
      case 'D':
        dest = {i, j};
        break;
      case '*':
        qw.push({{i, j}, 0});
        vis[i][j] = true;
        break;
      }
  }

  int best = 10000;
  int t = 0;
  while (!qb.empty() || !qw.empty()) {
    while (!qw.empty()) {
      auto p = qw.front();
      if (p.se > t)
        break;
      qw.pop();
      for (auto d : dp) {
        auto np = p.fi + d;
        if (!valpos(np))
          continue;
        if (vis[np.fi][np.se])
          continue;
        if (v[np.fi][np.se] == '.') {
          v[np.fi][np.se] = '*';
          vis[np.fi][np.se] = true;
          qw.push({np, p.se + 1});
        }
      }
    }
    while (!qb.empty()) {
      auto p = qb.front();
      if (p.se > t)
        break;
      qb.pop();
      for (auto d : dp) {
        auto np = p.fi + d;
        if (!valpos(np))
          continue;
        if (v[np.fi][np.se] == 'D') {
          best = min(best, p.se + 1);
        }
        if (vis[np.fi][np.se])
          continue;
        if (v[np.fi][np.se] == '.') {
          vis[np.fi][np.se] = true;
          qb.push({np, p.se + 1});
        }
      }
    }

    t++;
  }

  if (best == 10000)
    cout << "KAKTUS";
  else
    cout << best;

  return 0;
}
