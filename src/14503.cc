#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second
#define DUST 0
#define WALL 1
#define CLEAN 2

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, m, d;
vector<vector<int>> room;
pp dps[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // N E S W
pp operator+(const pp &p1, const pp &p2) {
  return {p1.fi + p2.fi, p1.se + p2.se};
}
// bool validpos(const pp &p) {
//   return (p.fi >= 0) && (p.fi < n) && (p.se >= 0) && (p.se < m);
// }

void turn(int angle) { d = (d + angle) % 4; }

bool sideallclean(const pp &p) {
  for (auto dp : dps) {
    pp np = p + dp;
    // if (!validpos(p))
    //   continue;
    if (room[np.fi][np.se] == 0)
      return false;
  }
  return true;
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int cleaned = 0;
  pp p;
  cin >> n >> m >> p.fi >> p.se >> d;
  room.resize(n);
  for (int i = 0; i < n; i++) {
    room[i].resize(m);
    for (int j = 0; j < m; j++) {
      cin >> room[i][j];
    }
  }
  while (true) {
    if (room[p.fi][p.se] == DUST) {
      room[p.fi][p.se] = CLEAN;
      cleaned++;
    }
    if (sideallclean(p)) {
      turn(2);
      if (room[p.fi + dps[d].fi][p.se + dps[d].se] == WALL)
        break;
      p.fi += dps[d].fi;
      p.se += dps[d].se;
      turn(2);
    } else {
      turn(3);
      if (room[p.fi + dps[d].fi][p.se + dps[d].se] == DUST) {
        p.fi += dps[d].fi;
        p.se += dps[d].se;
      }
    }
  }
  cout << cleaned;

  return 0;
}
