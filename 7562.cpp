#include <iostream>
#include <queue>

using namespace std;
int board[300][300];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  int len;
  queue<pair<int, int>> q;
  for (int tt = 0; tt < t; tt++) {
    cin >> len;
    for (int i = 0; i < len; i++)
      for (int j = 0; j < len; j++)
        board[i][j] = 0;
    int x, y;
    cin >> x >> y;
    q.push(make_pair(x, y));
    board[x][y] = 1;

    while (!q.empty()) {
      int xx = q.front().first;
      int yy = q.front().second;
      int dis = board[xx][yy];
      q.pop();
      for (int i = 0; i < 8; i++) {
        int nx = xx + dx[i];
        int ny = yy + dy[i];
        if (nx < 0 || ny < 0 || nx >= len || ny >= len)
          continue;
        if (board[nx][ny] == 0) {
          board[nx][ny] = dis + 1;
          q.push(make_pair(nx, ny));
        }
      }
    }
    cin >> x >> y;
    cout << board[x][y] - 1 << '\n';
  }

  return 0;
}