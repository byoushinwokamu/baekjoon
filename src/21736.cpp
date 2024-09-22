#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char campus[600][600];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int p = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    cin >> campus[i];
    for (int j = 0; j < m; j++) {
      if (campus[i][j] == 'I')
        q.push({i, j});
    }
  }
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      auto next = make_pair(now.first + dx[i], now.second + dy[i]);
      if (next.first < 0 || next.second < 0 || next.first >= n ||
          next.second >= m)
        continue;
      switch (campus[next.first][next.second]) {
      case 'P':
        p++;
      case 'O':
        campus[next.first][next.second] = 0;
        q.push({next.first, next.second});
      }
    }
  }

  if (p)
    cout << p;
  else
    cout << "TT";

  return 0;
}