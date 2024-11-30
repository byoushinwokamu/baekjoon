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
typedef enum { NONE, RED, GREEN, FLOWER, LAKE } STATUS;
typedef struct {
  STATUS stat;
  int tim;
} cell;

int n, m, g, r, gr;
vector<vector<cell>> gd;
vector<pp> dropped;
vector<pp> yellow;
pp dps[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int maxflowers;

pp operator+(const pp &p1, const pp &p2) {
  return {p1.fi + p2.fi, p1.se + p2.se};
}
bool validpos(const pp &p) {
  return (p.fi >= 0) && (p.fi < n) && (p.se >= 0) && (p.se < m);
}

#define statnow g[now.fi][now.se].stat
#define timenow g[now.fi][now.se].tim
#define statnext g[np.fi][np.se].stat
#define timenext g[np.fi][np.se].tim

void evans(vector<vector<cell>> g) {
  int flowers = 0;
  queue<pp> q;
  for (auto d : dropped)
    q.push(d);

  while (!q.empty()) {
    pp now = q.front();
    q.pop();
    for (auto dp : dps) {
      pp np = now + dp;

      if (!validpos(np))
        continue;

      if (statnow == LAKE)
        cout << "E";
      if (statnow == FLOWER)
        cout << 'e';

      if (statnext == LAKE || statnext == FLOWER) {
        continue;
      }

      if (statnext == NONE) {
        bool tobeflower = false;
        for (auto ddp : dps) {
          pp nnp = ddp + np;
          if (!validpos(nnp))
            continue;
          if (nnp == now)
            continue;
          if ((g[nnp.fi][nnp.se].stat == GREEN && statnow == RED) ||
              (g[nnp.fi][nnp.se].stat == RED && statnow == GREEN))
            tobeflower = true;
        }
        if (tobeflower) {
          // cout << "FLOWER AT " << np.fi << ' ' << np.se << '\n';
          statnext = FLOWER;
          flowers++;
        } else {
          statnext = statnow;
          timenext = timenow + 1;
          q.push(np);
        }
      }
      // } else if (statnext == GREEN || statnext == RED) {
      //   if (statnext != statnow && timenow + 1 == timenext) {
      //     cout << "flower at " << np.fi << ' ' << np.se << '\n';
      //     statnext = FLOWER;
      //     flowers++;
      //   }
      // }
    }
  }
  if (flowers > maxflowers) {
    cout << "\nmaxf " << flowers << " at\n";
    for (auto a : g) {
      for (auto b : a)
        cout << 4 - b.stat << ' ';
      cout << endl;
    }
  }
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
      gd[yellow[i].fi][yellow[i].se].stat = GREEN;
      dfs(used + 1, i);
      gd[yellow[i].fi][yellow[i].se].stat = NONE;
      g++;
    }
    if (r) {
      r--;
      dropped[used] = yellow[i];
      gd[yellow[i].fi][yellow[i].se].stat = RED;
      dfs(used + 1, i);
      gd[yellow[i].fi][yellow[i].se].stat = NONE;
      r++;
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m >> g >> r;
  gr = g + r;
  int t;
  gd.resize(n);
  dropped.resize(gr);
  for (int i = 0; i < n; i++) {
    gd[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> t;
      if (t == 0)
        gd[i][j].stat = LAKE;
      else if (t == 2)
        yellow.push_back({i, j});
    }
  }
  dfs(0, -1);
  cout << maxflowers;

  return 0;
}
