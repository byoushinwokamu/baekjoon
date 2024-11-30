#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

#define HOSU 0        // 0b00000
#define WHITE 1       // 0b00001
#define YELLOW 2      // 0b00010
#define RBIT 4        // 0b00100
#define GBIT 8        // 0b01000
#define FBIT 16       // 0b10000
#define CHECKWATER 12 // 0b01100
#define CHECKEMPTY 28 // 0b11100

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, m;
int g, r;
int ly, by;
int maxflower;
vector<vector<pp>> gd; // fi: 땅의 타입, se: 배양액이 퍼졌다면 퍼진 시간
vector<vector<pp>> garden_temp;
vector<pp> yland;
vector<pp> water;

bool validpos(const pp &p) {
  return (p.fi >= 0) && (p.fi < n) && (p.se >= 0) && (p.se < m);
}

pp operator+(const pp &p1, const pp &p2) {
  return {p1.fi + p2.fi, p1.se + p2.se};
}

pp dps[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void yoshitaka() {
  int flower = 0;
  queue<pp> q;
  for (auto w : water)
    q.push(w);
  // 처음엔 fbit 문제 없음

  while (!q.empty()) {
    pp now = q.front();
    q.pop();

    for (auto dp : dps) {
      pp np = dp + now;
      if (!validpos(np))
        continue;

      if (gd[np.fi][np.se].fi == HOSU)
        continue;

      if (gd[np.fi][np.se].fi & FBIT)
        continue;
      else if (gd[np.fi][np.se].fi & RBIT) {
        if (gd[now.fi][now.se].fi & GBIT) {
          if (gd[np.fi][np.se].se == gd[now.fi][now.se].se + 1) {
            gd[np.fi][np.se].fi |= FBIT;
            flower++;
          }
        }
      } else if (gd[np.fi][np.se].fi & GBIT) {
        if (gd[now.fi][now.se].fi & RBIT) {
          if (gd[np.fi][np.se].se == gd[now.fi][now.se].se + 1) {
            gd[np.fi][np.se].fi |= FBIT;
            flower++;
          }
        }
      } else {
        gd[np.fi][np.se].fi |= gd[now.fi][now.se].fi & CHECKWATER;
        gd[np.fi][np.se].se = gd[now.fi][now.se].se + 1;
        q.push(np);
      }

      // go to empty land
      // if (!(gd[np.fi][np.se].fi & CHECKEMPTY)) {
      //   // gd[np.fi][np.se].fi |= (gd[now.fi][now.se].fi &
      //   // CHECKEMPTY);
      //   gd[np.fi][np.se].fi |= (gd[now.fi][now.se].fi & CHECKWATER);
      //   // if (gd[now.fi][now.se].fi & GBIT)
      //   //   gd[np.fi][np.se].fi |= GBIT;
      //   // if (gd[now.fi][now.se].fi & RBIT)
      //   //   gd[np.fi][np.se].fi |= RBIT;
      //   gd[np.fi][np.se].se = gd[now.fi][now.se].se + 1;
      //   q.push(np);

      // } else { // not empty, there is some 배양액
      //   // rendez-vous of different color
      //   if (((gd[np.fi][np.se].fi & CHECKWATER) ^
      //        (gd[now.fi][now.se].fi & CHECKWATER)) == CHECKWATER) {
      //     if (gd[np.fi][np.se].se == gd[now.fi][now.se].se + 1) {
      //       gd[np.fi][np.se].fi |= FBIT;
      //       flower++;
      //     }
      //   }
      // }
    } // end for
  } // end while

  maxflower = max(flower, maxflower);
  return;
}

void dfs(int used, int last) {
  if (used == by) {
    gd = garden_temp;
    yoshitaka();
    return;
  }

  for (int i = last + 1; i < ly; i++) {
    water[used] = {yland[i].fi, yland[i].se};
    if (g) {
      g--;
      garden_temp[yland[i].fi][yland[i].se].fi |= GBIT;
      dfs(used + 1, i);
      garden_temp[yland[i].fi][yland[i].se].fi &= ~GBIT;
      g++;
    }
    if (r) {
      r--;
      garden_temp[yland[i].fi][yland[i].se].fi |= RBIT;
      dfs(used + 1, i);
      garden_temp[yland[i].fi][yland[i].se].fi &= ~RBIT;
      r++;
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

  cin >> n >> m >> g >> r;
  by = g + r;
  garden_temp.resize(n);
  water.resize(by);

  for (int i = 0; i < n; i++) {
    garden_temp[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> garden_temp[i][j].fi;
      if (garden_temp[i][j].fi == YELLOW)
        yland.push_back({i, j}), ly++;
    }
  }

  dfs(0, -1);
  cout << maxflower;

  return 0;
}
