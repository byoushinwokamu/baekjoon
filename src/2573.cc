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

int n, m;
int land;

pp operator+(const pp &p1, const pp &p2) {
  return {p1.fi + p2.fi, p1.se + p2.se};
}

bool validpos(pp p) {
  return (p.fi >= 0) && (p.fi < n) && (p.se >= 0) && (p.se < m);
}

pp dp[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool melt(vector<vector<int>> &bs) {
  bool melted = false;
  vector<vector<int>> dbs(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!bs[i][j])
        continue;
      melted = true;
      pp p = {i, j};
      for (auto d : dp) {
        pp np = p + d;
        if (validpos(np) && !bs[np.fi][np.se])
          dbs[i][j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bs[i][j] = (bs[i][j] > dbs[i][j] ? bs[i][j] - dbs[i][j] : 0);
      land += (!bs[i][j] && dbs[i][j] ? -1 : 0);
    }
  }
  return melted;
}

bool onepiece(vector<vector<int>> &bs) {
  int psize = 1;
  queue<pp> q;
  vector<vector<bool>> vis(n, vector<bool>(m));

  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (bs[i][j]) {
        q.push({i, j});
        vis[i][j] = true;
        break;
      }
    }
    if (!q.empty())
      break;
  }
  if (q.empty()) {
    cout << 0;
    exit(0);
  }

  while (!q.empty()) {
    pp now = q.front();
    q.pop();

    for (auto d : dp) {
      pp np = d + now;
      if (!vis[np.fi][np.se] && bs[np.fi][np.se]) {
        vis[np.fi][np.se] = true;
        q.push(np);
        psize++;
      }
    }
  }
  // cout << "psize" << psize << '\n';
  return psize == land;
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m;
  vector<vector<int>> bs(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> bs[i][j];
      if (bs[i][j])
        land++;
    }

  bool m = true;
  for (int y = 0;; y++) {
    // cout << '\n';
    if (!melt(bs)) {
      cout << 0;
      break;
    }
    // for (auto a : bs) {
    //   for (auto b : a)
    //     cout << b << ' ';
    //   cout << '\n';
    // }
    if (!onepiece(bs)) {
      // cout << "land" << land << '\n';
      cout << y + 1;
      break;
    }
  }

  return 0;
}
