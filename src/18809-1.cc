// BOJ 18809-1
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
typedef enum { LAKE, SPACE, GREEN, RED, FLOWER } cellstat;

typedef struct {
  cellstat stat;
  int t;
} cell;

const pp dp[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pp operator+(const pp &p1, const pp &p2) {
  return {p1.fi + p2.fi, p1.se + p2.se};
}

int n, m, g, r, t, gr, flmax = 0;
vector<vector<cell>> garden_ori;
vector<pp> yellow;
vector<pp> water;

bool validpos(const pp &p) {
  return p.fi >= 0 && p.fi < n && p.se >= 0 && p.se < m;
}

int selcnt = 1;
void execute(vector<vector<cell>> garden) {
  queue<pp> q;
  vector<vector<bool>> vis(n, vector<bool>(m));
  for (auto w : water)
    q.push(w);

  while (true) {
    auto p = q.front();
    if (garden[p.fi][p.se].stat == SPACE)
      break;
    q.pop();
    for (auto d : dp) {
      auto np = p + d;
      if (!validpos(np))
        continue;
      if (garden[np.fi][np.se].stat == SPACE && !vis[np.fi][np.se]) {
        vis[np.fi][np.se] = true;
        q.push(np);
      }
    }
  }

  int fl = 0;
  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    int gg = 1000, rr = 1000;
    for (auto d : dp) {
      auto x = p + d;
      if (!validpos(x))
        continue;
      if (garden[x.fi][x.se].stat == RED)
        rr = min(rr, garden[x.fi][x.se].t + 1);
      if (garden[x.fi][x.se].stat == GREEN)
        gg = min(gg, garden[x.fi][x.se].t + 1);
    }

    if (rr == gg) {
      garden[p.fi][p.se].stat = FLOWER;
      garden[p.fi][p.se].t = rr;
      fl++;
      continue;
    } else if (rr < gg) {
      garden[p.fi][p.se].stat = RED;
      garden[p.fi][p.se].t = rr;
      vis[p.fi][p.se] = true;
    } else {
      garden[p.fi][p.se].stat = GREEN;
      garden[p.fi][p.se].t = gg;
      vis[p.fi][p.se] = true;
    }

    for (auto d : dp) {
      auto x = p + d;
      if (!validpos(x))
        continue;
      if (garden[x.fi][x.se].stat == SPACE && !vis[x.fi][x.se])
        q.push(x);
    }
  }
  // debug print
  // if (fl > flmax) {
  //   cout << selcnt++ << "========\n";
  //   for (auto a : garden_ori) {
  //     for (auto b : a) {
  //       switch (b.stat) {
  //       case LAKE:
  //         cout << "@ ";
  //         break;
  //       case SPACE:
  //         cout << "_ ";
  //         break;
  //       case GREEN:
  //         cout << "G ";
  //         break;
  //       case RED:
  //         cout << "R ";
  //         break;
  //       }
  //     }
  //     cout << '\n';
  //   }
  //   cout << '\n';
  //   cout << endl;
  //   for (auto a : garden) {
  //     for (auto b : a) {
  //       switch (b.stat) {
  //       case LAKE:
  //         cout << "@ ";
  //         break;
  //       case SPACE:
  //         cout << "_ ";
  //         break;
  //       case GREEN:
  //         cout << "G ";
  //         break;
  //       case RED:
  //         cout << "R ";
  //         break;
  //       case FLOWER:
  //         cout << "% ";
  //         break;
  //       }
  //     }
  //     cout << '\n';
  //   }
  //   cout << "======= fl = " << fl << "\n";
  // }
  //
  fl = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (garden[i][j].stat == FLOWER)
        fl++;

  flmax = max(flmax, fl);
}

void select(int level) {
  if (level == yellow.size()) {
    if (water.size() != gr)
      return;
    // debug print
    // cout << selcnt++ << "========\n";
    // for (auto a : garden_ori) {
    //   for (auto b : a) {
    //     switch (b.stat) {
    //     case LAKE:
    //       cout << "@ ";
    //       break;
    //     case SPACE:
    //       cout << "_ ";
    //       break;
    //     case GREEN:
    //       cout << "G ";
    //       break;
    //     case RED:
    //       cout << "R ";
    //       break;
    //     }
    //   }
    //   cout << '\n';
    // }
    // cout << '\n';
    //

    execute(garden_ori);
    return;
  }
  // cout << "LEVEL " << level << " START\n";
  if (r) {
    // cout << "MARK RED\n";
    garden_ori[yellow[level].fi][yellow[level].se].stat = RED;
    water.push_back(yellow[level]);
    r--;
    select(level + 1);
    garden_ori[yellow[level].fi][yellow[level].se].stat = SPACE;
    water.pop_back();
    r++;
    // cout << "ERASE RED\n";
  }
  if (g) {
    // cout << "MARK GREEN\n";
    garden_ori[yellow[level].fi][yellow[level].se].stat = GREEN;
    water.push_back(yellow[level]);
    g--;
    select(level + 1);
    garden_ori[yellow[level].fi][yellow[level].se].stat = SPACE;
    water.pop_back();
    g++;
    // cout << "ERASE GREEN\n";
  }
  select(level + 1);

  // cout << "LEVEL " << level << " END\n";
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m >> g >> r;
  gr = g + r;

  garden_ori.resize(n);
  for (int i = 0; i < n; i++) {
    garden_ori[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> t;
      if (t == 0)
        garden_ori[i][j].stat = LAKE;
      else if (t == 1)
        garden_ori[i][j].stat = SPACE;
      else if (t == 2)
        garden_ori[i][j].stat = SPACE, yellow.push_back({i, j});
      garden_ori[i][j].t = 0;
    }
  }
  // cout << "YELLOW----\n";
  // for (auto y : yellow) {
  // cout << y.fi << ',' << y.se << '\n';
  // }

  select(0);
  cout << flmax;

  return 0;
}
