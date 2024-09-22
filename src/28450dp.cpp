#include <iostream>
#include <vector>

using namespace std;

int n, m, h, diag;
int gym[1000][1000];
typedef long long ll;
vector<vector<ll>> opt(1000);
typedef pair<int, int> pos;

bool validpos(pos p) {
  if (p.first < 0 || p.second < 0 || p.first >= n || p.second >= m)
    return false;
  return true;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m;
  pos dest = {n - 1, m - 1};
  for (int i = 0; i < n; i++) {
    opt[i] = vector<ll>(1000, -1);
    for (int j = 0; j < m; j++)
      cin >> gym[i][j];
  }
  cin >> h;
  opt[0][0] = gym[0][0];
  diag = n + m - 1;
  for (int i = 0; i < diag; i++) {
    for (int j = 0; j < diag; j++) {
      int x = j, y = i - j;
      if (!validpos({x, y}))
        continue;
      if (validpos({x - 1, y})) {
        opt[x][y] = opt[x - 1][y] + gym[x][y];
      }
      if (validpos({x, y - 1})) {
        if (opt[x][y] == -1)
          opt[x][y] = opt[x][y - 1] + gym[x][y];
        else
          opt[x][y] = min(opt[x][y], opt[x][y - 1] + gym[x][y]);
      }
    }
  }

  if (opt[n - 1][m - 1] > h || opt[n - 1][m - 1] == -1)
    cout << "NO";
  else
    cout << "YES\n" << opt[n - 1][m - 1];

  return 0;
}