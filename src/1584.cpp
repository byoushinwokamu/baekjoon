#include <deque>
#include <iostream>
#define DAN 1
#define DEA 2

using namespace std;

int reg[501][501];
int lif[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, x1, y1, x2, y2, t;
deque<pair<int, int>> d;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2)
      t = x1, x1 = x2, x2 = t;
    if (y1 > y2)
      t = y1, y1 = y2, y2 = t;
    for (int j = x1; j <= x2; j++)
      for (int k = y1; k <= y2; k++)
        reg[j][k] = DAN;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2)
      t = x1, x1 = x2, x2 = t;
    if (y1 > y2)
      t = y1, y1 = y2, y2 = t;
    for (int j = x1; j <= x2; j++)
      for (int k = y1; k <= y2; k++)
        reg[j][k] = DEA;
  }

  d.push_back(make_pair(0, 0));
  lif[0][0] = 1;
  int nx, ny;
  while (!d.empty()) {
    int x = d.front().first;
    int y = d.front().second;
    d.pop_front();
    if (x == 500 && y == 500) {
      cout << lif[500][500] - 1;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      nx = x + dx[i];
      ny = y + dy[i];
      if (nx < 0 || nx > 500 || ny < 0 || ny > 500)
        continue;
      if (reg[nx][ny] == DEA)
        continue;
      else if (reg[nx][ny] == DAN && !lif[nx][ny]) {
        lif[nx][ny] = lif[x][y] + 1;
        d.push_back(make_pair(nx, ny));
      } else if (!lif[nx][ny]) {
        lif[nx][ny] = lif[x][y];
        d.push_front(make_pair(nx, ny));
      }
    }
  }
  cout << -1;
  return 0;
}