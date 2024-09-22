#include <iostream>
#include <queue>

using namespace std;

int n, m, h;
int gym[1000][1000];
int opt[1000][1000];
int maxh = -1;
typedef pair<int, int> pos;
pos diff[2] = {{1, 0}, {0, 1}};
queue<pair<pos, int>> way;

bool validpos(pos p) {
  if (p.first >= n || p.second >= m)
    return false;
  return true;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m;
  pos dest = {n - 1, m - 1};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> gym[i][j];
  cin >> h;
  way.push(make_pair(make_pair(0, 0), h - gym[0][0]));
  opt[0][0] = h - gym[0][0];

  while (!way.empty()) {
    pos now = way.front().first;
    int hn = way.front().second;
    way.pop();
    if (opt[now.first][now.second] != hn)
      continue;
    for (auto d : diff) {
      pos next = {now.first + d.first, now.second + d.second};
      if (!validpos(next))
        continue;
      int hnex = hn - gym[next.first][next.second];
      if (hnex < 0)
        continue;
      if (next == dest) {
        maxh = max(maxh, hnex);
      } else if (opt[next.first][next.second] < hnex ||
                 (opt[next.first][next.second] == 0 && hnex == 0)) {
        opt[next.first][next.second] = hnex;
        way.push({next, hnex});
      }
    }
  }

  if (maxh == -1)
    cout << "NO";
  else
    cout << "YES\n" << h - maxh;

  return 0;
}