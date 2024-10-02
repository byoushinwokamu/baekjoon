#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> pp;

int v[52][52];

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int r, c;
  string s;
  vector<pp> tostart;
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      if (s[j] == 'L') {
        v[i + 1][j + 1] = 1;
        tostart.push_back({i + 1, j + 1});
      }
    }
  }

  int maxlen = 0;
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
  for (auto st : tostart) {
    queue<pair<pp, int>> q;
    vector<vector<bool>> vis(52, vector<bool>(52));
    q.push({st, 0});
    vis[st.fi][st.se] = true;

    while (!q.empty()) {
      auto now = q.front();
      q.pop();
      for (int d = 0; d < 4; d++) {
        if (v[now.fi.fi + dx[d]][now.fi.se + dy[d]] &&
            !vis[now.fi.fi + dx[d]][now.fi.se + dy[d]]) {
          vis[now.fi.fi + dx[d]][now.fi.se + dy[d]] = true;
          q.push({{now.fi.fi + dx[d], now.fi.se + dy[d]}, now.se + 1});
          maxlen = max(maxlen, now.se + 1);
        }
      }
    }
  }
  cout << maxlen << '\n';

  return 0;
}