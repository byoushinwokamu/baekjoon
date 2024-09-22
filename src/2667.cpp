#include <functional>
#include <iostream>
#include <queue>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int paper[25][25];
// 0이 빈칸, 1이 집있는칸/탐색한칸

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int m, n;
  cin >> m;
  n = m;
  queue<pair<int, int>> q;
  char info[26];

  for (int i = 0; i < n; i++) {
    cin >> info;
    for (int j = 0; j < n; j++)
      paper[i][j] = -(int)(info[j] - 49);
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
    cout << -pq.top() << "\n";
    pq.pop();
  }
  return 0;
}