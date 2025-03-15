// BOJ 18809-1
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second
#define debug

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
typedef enum { LAKE, SPACE, RED, GREEN } cellstat;

typedef struct {
  cellstat stat;
} cell;

const pp dp[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pp operator+(const pp &p1, const pp &p2) {
  return {p1.fi + p2.fi, p1.se + p2.se};
}

int n, m, g, r, t, gr, flmax = 0;
int selcnt;
vector<vector<cell>> garden_ori;
vector<pp> yellow;
vector<pp> red, green;

bool validpos(const pp &p) {
  return p.fi >= 0 && p.fi < n && p.se >= 0 && p.se < m;
}

void execute() {
  int fl = 0;
  queue<pp> qr, qg;
  vector<vector<int>> vr(n, vector<int>(m)), vg(n, vector<int>(m));

  for (auto w : red)
    qr.push(w), vr[w.fi][w.se] = 1;

  for (auto w : green)
    qg.push(w), vg[w.fi][w.se] = 1;

  while (!qr.empty()) {
    auto p = qr.front();
    qr.pop();

    for (auto d : dp) {
      auto np = p + d;
      if (!validpos(np))
        continue;
      if (vr[np.fi][np.se] || vg[np.fi][np.se])
        continue;
      if (garden_ori[np.fi][np.se].stat == LAKE)
        continue;
      vr[np.fi][np.se] = vr[p.fi][p.se] + 1;
      qr.push(np);
    }
  }

  while (!qg.empty()) {
    auto p = qg.front();
    qg.pop();

    for (auto d : dp) {
      auto np = p + d;
      if (!validpos(np))
        continue;
      if (vg[np.fi][np.se])
        continue;
      if (garden_ori[np.fi][np.se].stat == LAKE)
        continue;
      vg[np.fi][np.se] = vg[p.fi][p.se] + 1;

      if (vg[np.fi][np.se] > vr[np.fi][np.se])
        continue;
      if (vg[np.fi][np.se] == vr[np.fi][np.se])
        fl++;
      else
        qg.push(np);
    }
  }

  // debug print
#ifdef debug
  if (fl > flmax) {
    cout << "EXE " << selcnt << "========\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        switch (garden_ori[i][j].stat) {
        case LAKE:
          cout << "  ";
          break;
        case SPACE:
          cout << ". ";
          break;
        case RED:
          cout << "R ";
          break;
        case GREEN:
          cout << "G ";
          break;
        }
      }
      cout << endl;
    }
    cout << "RED\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (garden_ori[i][j].stat == LAKE)
          cout << "  ";
        else {
          if (vr[i][j] == 0)
            cout << ". ";
          else if (garden_ori[i][j].stat == SPACE)
            cout << vr[i][j] << ' ';
        }
      }
      cout << endl;
    }
    cout << "GREEN\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (garden_ori[i][j].stat == LAKE)
          cout << "  ";
        else {
          if (vg[i][j] == 0)
            cout << ". ";
          else if (garden_ori[i][j].stat == SPACE)
            cout << vg[i][j] << ' ';
        }
      }
      cout << endl;
    }

    cout << "------- fl = " << fl << "\n";
  }
#endif

  flmax = max(flmax, fl);
}

void select(int level) {
  if (level == yellow.size()) {
    if (green.size() + red.size() != gr)
      return;
    selcnt++;
    execute();
    return;
  }
  if (r) {
    garden_ori[yellow[level].fi][yellow[level].se].stat = RED;
    red.push_back(yellow[level]);
    r--;
    select(level + 1);
    garden_ori[yellow[level].fi][yellow[level].se].stat = SPACE;
    red.pop_back();
    r++;
  }
  if (g) {
    garden_ori[yellow[level].fi][yellow[level].se].stat = GREEN;
    green.push_back(yellow[level]);
    g--;
    select(level + 1);
    garden_ori[yellow[level].fi][yellow[level].se].stat = SPACE;
    green.pop_back();
    g++;
  }
  select(level + 1);
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
    }
  }

  select(0);
#ifdef debug
  cout << "sel " << selcnt << endl;
#endif
  cout << flmax;

  return 0;
}
