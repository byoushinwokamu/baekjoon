#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second
#define NOVISIT 2000000000
typedef long long ll;

using namespace std;

vector<vector<int>> v(1002, vector<int>(1002));
// 0: unbreakable wall, 1: breakable wall, 2: way
vector<vector<int>> disnb(1002, vector<int>(1002, NOVISIT));
vector<vector<int>> disyb(1002, vector<int>(1002, NOVISIT));

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 1; j <= m; j++) {
      v[i][j] = (s[j - 1] == '0' ? 2 : 1);
    }
  }

  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};

  queue<pair<pair<int, int>, bool>> q;
  q.push({{1, 1}, false});
  disnb[1][1] = 1;
  disyb[1][1] = 1;

  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = now.fi.fi + dx[i];
      int ny = now.fi.se + dy[i];
      int lyb = disyb[now.fi.fi][now.fi.se];
      int lnb = disnb[now.fi.fi][now.fi.se];
      int nyb = disyb[nx][ny];
      int nnb = disnb[nx][ny];

      if (nx == n && ny == m) {              // reached finish point
        if (now.se)                          // broke a wall
          disyb[nx][ny] = min(nyb, lyb + 1); // update when faster
        else if (nnb == NOVISIT)             // first reach w/o breaking
          disnb[nx][ny] = lnb + 1;           // save distance

      } else if (v[nx][ny] == 1 && !now.se) { // encounter breakable wall
        if (nyb == NOVISIT)
          disyb[nx][ny] = lnb + 1, q.push({{nx, ny}, true});

      } else if (v[nx][ny] == 2) { // encount just way
        if (now.se) {              // did break wall
          if (nyb == NOVISIT)      // didn't come after break
            disyb[nx][ny] = lyb + 1,
            q.push({{nx, ny}, true}); // save distance and keep going
          else if (nyb > lyb + 1)     // is faster way
            disyb[nx][ny] = lyb + 1,
            q.push({{nx, ny}, true}); // save distance and keep going
          else
            ;
        } else if (disnb[nx][ny] ==
                   NOVISIT) { // didn't break wall and not visited
          disnb[nx][ny] = lnb + 1, q.push({{nx, ny}, false});
        }
      }
    }
  }
  int mindis;
  if (disnb[n][m] == NOVISIT)
    mindis = disyb[n][m];
  else if (disyb[n][m] == NOVISIT)
    mindis = disnb[n][m];
  else
    mindis = min(disnb[n][m], disyb[n][m]);

  bool cant = disnb[n][m] == NOVISIT && disyb[n][m] == NOVISIT;
  cout << "\ndisnb\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      cout << disnb[i][j] << ' ';
    cout << endl;
  }
  cout << "\ndisyb\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      cout << disyb[i][j] << ' ';
    cout << endl;
  }
  cout << (cant ? -1 : mindis);

  return 0;
}
