#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> point; // <row, column>
int firemap[1000][1000];
int jhmap[1000][1000];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
queue<point> q;
char mapdata[1001];
//-1: 벽
// 0:공간
// n: n-1분 후 불이 번짐(firemap)/도착 가능(jhmap)

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int ct = 0; ct < t; ct++) {
    int r, c;
    cin >> c >> r;

    int startx, starty;
    for (int i = 0; i < r; i++) {
      cin >> mapdata;
      for (int j = 0; j < c; j++)
        switch (mapdata[j]) {
        case '#':
          firemap[i][j] = -1;
          jhmap[i][j] = -1;
          break;
        case '.':
          firemap[i][j] = 0;
          jhmap[i][j] = 0;
          break;
        case '@':
          jhmap[i][j] = 1;
          startx = i;
          starty = j;
          break;
        case '*':
          firemap[i][j] = 1;
          q.push(make_pair(i, j));
          break;
        }
    }

    int x, y, firemin, jhmin;
    while (!q.empty()) {
      point np = q.front();
      firemin = firemap[np.first][np.second] + 1;
      q.pop();
      for (int i = 0; i < 4; i++) {
        x = np.first + dr[i];
        y = np.second + dc[i];
        if (x < 0 || y < 0 || x >= r || y >= c)
          continue;
        if (firemap[x][y] == 0) {
          firemap[x][y] = firemin;
          q.push(make_pair(x, y));
        }
      }
    }

    q.push(make_pair(startx, starty));
    bool escape = false;
    while (!q.empty()) {
      point np = q.front();
      jhmin = jhmap[np.first][np.second] + 1;
      q.pop();
      for (int i = 0; i < 4; i++) {
        x = np.first + dr[i];
        y = np.second + dc[i];
        if (x < 0 || y < 0 || x >= r || y >= c) {
          cout << jhmin - 1 << '\n';
          escape = true;
          break;
        }
        if (jhmap[x][y] == 0 && (firemap[x][y] == 0 || firemap[x][y] > jhmin)) {
          jhmap[x][y] = jhmin;
          q.push(make_pair(x, y));
        }
      }
      if (escape)
        break;
    }
    if (!escape)
      cout << "IMPOSSIBLE\n";
  }
  return 0;
}