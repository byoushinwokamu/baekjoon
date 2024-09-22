#include <functional>
#include <iostream>
#include <queue>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int paper[100][100];
// 0이 빈칸, 1이 직사각형이 있는칸 or 탐색이 완료된 칸

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int m, n, k;
  cin >> m >> n >> k;
  queue<pair<int, int>> q;

  for (int i = 0; i < k; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int x = x1; x < x2; x++)
      for (int y = y1; y < y2; y++)
        paper[y][x] = 1;
  }

  int count = 0;
  priority_queue<int> pq;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (paper[i][j] != 0)
        continue;
      int area = 0;
      q.push(make_pair(i, j));
      paper[i][j] = 1;
      area++;
      count++;
      while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;
          if (paper[nx][ny] == 0) {
            paper[nx][ny] = 1;
            area++;
            q.push(make_pair(nx, ny));
          }
        }
      }
      pq.push(-area);
    }
  }
  cout << count << "\n";
  while (!pq.empty()) {
    cout << -pq.top() << " ";
    pq.pop();
  }
  return 0;
}