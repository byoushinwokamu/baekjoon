#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second
#define sta first
#define tim second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

#define LAKE 0
#define NO 1
#define RED 2
#define GREEN 3
#define FLOWER 4

int n, m, nm, g, r, gr, y, t;
vector<pp> gd;
vector<pp> gdc;
vector<int> yable;
vector<int> yreal;
int dps[4];
int mf;

bool validpos(const int &p) { return (p >= 0) && (p < nm); }
bool validmove(const int &p, const int &dp) {
  if (abs(dp) == 1) {
    return ((p / m) == ((p + dp) / m));
  } else {
    return true;
  }
}

void dj_yoshitaka(void) {
  queue<int> q;
  int f = 0;
  for (auto a : yreal)
    q.push(a);

  while (!q.empty()) {
    int now = q.front();
    int nowt = gdc[now].tim;
    q.pop();

    for (auto dp : dps) {
      int next = now + dp;
      if (!validpos(next) || !validmove(now, dp))
        continue;

      if (gdc[next].sta == NO) {
        bool bloom = false;

        for (auto ddp : dps) {
          int nx = next + ddp;
          if (!validpos(nx) || !validmove(next, ddp) || nx == now)
            continue;

          switch (gdc[nx].sta) {
          case LAKE:
          case FLOWER:
          case NO:
            continue;
          case GREEN:
          case RED:
            if (gdc[now].sta != gdc[nx].sta && gdc[now].tim == gdc[nx].tim) {
              bloom = true;
              // cout << "Bloom at " << next / m + 1 << ',' << next % m + 1
              //      << " by " << dp << ',' << ddp << endl;
            }
            break;
          }
        } // end for-each

        if (bloom) {
          gdc[next].sta = FLOWER;
          f++;
        } else if (gdc[next].sta == NO) {
          gdc[next].sta = gdc[now].sta;
          gdc[next].tim = gdc[now].tim + 1;
          q.push(next);
        }
        break;

      } // end if ( next == no )
    } // end for-each
  } // end while

  // debug print
  // if (f > mf) {
  //   for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < m; j++)
  //       cout << gdc[i * m + j].fi << ' ';
  //     cout << endl;
  //   }
  //   cout << endl;
  // }
  mf = max(f, mf);
}

void dfs(int depth, int last) {
  if (depth == gr) {
    gdc = gd;
    dj_yoshitaka();
    return;
  }
  for (int i = last + 1; i < y; i++) {
    yreal[depth] = yable[i];
    if (g) {
      g--;
      gd[yable[i]].sta = GREEN;
      dfs(depth + 1, i);
      gd[yable[i]].sta = NO;
      g++;
    }
    if (r) {
      r--;
      gd[yable[i]].sta = RED;
      dfs(depth + 1, i);
      gd[yable[i]].sta = NO;
      r++;
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m >> g >> r;
  nm = n * m;
  gr = g + r;
  gd.resize(nm);
  yreal.resize(gr);
  dps[0] = m;
  dps[1] = -m;
  dps[2] = 1;
  dps[3] = -1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t;
      switch (t) {
      case 0:
        gd[i * m + j].sta = LAKE;
        break;
      case 1:
        gd[i * m + j].sta = NO;
        break;
      case 2:
        gd[i * m + j].sta = NO;
        y++, yable.push_back(i * m + j);
        break;
      }
    }
  }

  dfs(0, -1);
  // cout << y << ' ' << cnt << endl;
  cout << mf;

  return 0;
}
