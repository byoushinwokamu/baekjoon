#include <iostream>
#include <queue>
#include <string>

using namespace std;
int r, c, bd;
int board[1000000];
queue<pair<int, int>> q;
// second int means route length
// route length is shorter than 1,000,000
// therefore, we will use if length is 1,000,000+l,
// it means length of l and this route has broke a wall.

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> r >> c;
  bd = r * c;
  string t;
  for (int i = 0; i < r; i++) {
    cin >> t;
    for (int j = 0; j < c; j++)
      board[i * r + j] = (int)t[j] - '0';
  }

  q.push(make_pair(0, 1));
  while (!q.empty()) {
    int now = q.front().first;
    int len = q.front().second;
    bool brk = len > 1000000;
    q.pop();
    if (now == bd - 1) {
      if (brk)
        len -= 1000000;
      cout << len;
      return 0;
    }

    if (now >= c) {
      if (!brk && board[now - c] == 1) {
        q.push(make_pair(now - c, len + 1000001));
      } else if (board[now - c] == 0) {
        board[now - c] = 2;
        q.push(make_pair(now - c, len + 1));
      }
    }
    if (now < bd - c) {
      if (!brk && board[now + c] == 1) {
        q.push(make_pair(now + c, len + 1000001));
      } else if (board[now + c] == 0) {
        board[now + c] = 2;
        q.push(make_pair(now + c, len + 1));
      }
    }
    if (now % c > 0) {
      if (!brk && board[now - 1] == 1) {
        q.push(make_pair(now - 1, len + 1000001));
      } else if (board[now - 1] == 0) {
        board[now - 1] = 2;
        q.push(make_pair(now - 1, len + 1));
      }
    }
    if (now % c < c - 1) {
      if (!brk && board[now + 1] == 1) {
        q.push(make_pair(now + 1, len + 1000001));
      } else if (board[now + 1] == 0) {
        board[now + 1] = 2;
        q.push(make_pair(now + 1, len + 1));
      }
    }
  }
  cout << -1;
  return 0;
}