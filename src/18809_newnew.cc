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
typedef enum { NONE, RED, GREEN, FLOWER, LAKE } cell;

int n, m, g, r, gr, nm;
vector<cell> gd;
vector<int> dropped;
vector<int> yellow;
int dps[4];
int maxflowers;

bool validpos(const int &p) { return (p >= 0) && (p < nm); }

void evans(vector<cell> g) {
  int flowers = 0;
  queue<pp> q;
  for (auto d : dropped)
    q.push({d, 0});

  while (!q.empty()) {
    int now = q.front().fi;
    int tim = q.front().se;
    q.pop();
    for (auto dp : dps) {
      int next = now + dp;

      if (!validpos(next))
        continue;

      // if (g[now] == LAKE)
      //   cout << "E";
      // if (g[now] == FLOWER)
      //   cout << 'e';

      if (g[next] == LAKE || g[next] == FLOWER)
        continue;

      // else: g[next] is NONE or GREEN or RED
      if (g[next] == NONE) {
        bool bloom = false;
        for (auto ddp : dps) {
          int nnx = next + ddp;
          if (!validpos(nnx))
            continue;
          if ((g[now] == GREEN && g[nnx] == RED) ||
              (g[now] == RED && g[nnx] == GREEN))
            bloom = true;
        }
        if (bloom) {
          flowers++, g[next] = FLOWER;
        } else {
          g[next] = g[now];
          q.push(next);
        }
      }
    } // end for-each
  } // end while

  maxflowers = max(flowers, maxflowers);
}

void dfs(int used, int last) {
  if (used == gr) {
    evans(gd);
    return;
  }
  for (int i = last + 1; i < yellow.size(); i++) {
    if (g) {
      g--;
      dropped[used] = yellow[i];
      gd[yellow[i]] = GREEN;
      dfs(used + 1, i);
      gd[yellow[i]] = NONE;
      g++;
    }
    if (r) {
      r--;
      dropped[used] = yellow[i];
      gd[yellow[i]] = RED;
      dfs(used + 1, i);
      gd[yellow[i]] = NONE;
      r++;
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m >> g >> r;
  nm = n * m;
  gr = g + r;
  int t;
  dps[0] = m;
  dps[1] = -m;
  dps[2] = 1;
  dps[3] = -1;

  gd.resize(nm);
  dropped.resize(gr);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t;
      if (t == 0)
        gd[m * i + j] = LAKE;
      else if (t == 2)
        yellow.push_back(m * i + j);
    }
  }
  dfs(0, -1);
  cout << maxflowers;

  return 0;
}
