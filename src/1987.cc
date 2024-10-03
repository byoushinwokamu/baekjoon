#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second
typedef long long ll;

using namespace std;
typedef pair<int, int> pos;

int r, c, maxdep;
vector<vector<int>> board(20, vector<int>(20));
int used;
pos next;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int depth, pos now) {
  maxdep = max(maxdep, depth);
  for (int i = 0; i < 4; i++) {
    pos next = {now.fi + dx[i], now.se + dy[i]};
    if (next.fi < 0 || next.fi >= r || next.se < 0 || next.se >= c)
      continue;
    if (!(used & (1 << board[next.fi][next.se]))) {
      used |= (1 << board[next.fi][next.se]);
      dfs(depth + 1, next);
      used &= ~(1 << board[next.fi][next.se]);
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> r >> c;
  string s;
  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      board[i][j] = s[j] - 'A';
    }
  }
  used |= (1 << board[0][0]);
  dfs(1, {0, 0});
  cout << maxdep;
  return 0;
}