#include <iostream>
#include <queue>

using namespace std;

int land[1000][1000];
int dist[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> land[i][j];
      if (land[i][j] == 2)
        q.push(make_pair(i, j)), dist[i][j]++;
    }

  while (!q.empty()) {
    auto now = q.front();
    int ndis = dist[now.first][now.second];
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = now.first + dx[i], ny = now.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (dist[nx][ny] != 0 || land[nx][ny] != 1)
        continue;
      dist[nx][ny] = ndis + 1;
      q.push(make_pair(nx, ny));
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << dist[i][j] - (land[i][j] ? 1 : 0) << ' ';
    cout << '\n';
  }

  return 0;
}