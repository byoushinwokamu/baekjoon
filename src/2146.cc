// BOJ 2146
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int n;
int board[100][100];
bool edge[100][100];
constexpr pp dp[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];

  int island = 2;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (board[i][j] != 1) continue;
      queue<pp> q;
      q.push({i, j});
      board[i][j] = island;
      while (!q.empty())
      {
        pp now = q.front();
        q.pop();
        for (auto d : dp)
        {
          pp next = {now.fi + d.fi, now.se + d.se};
          if (next.fi < 0 || next.se < 0 || next.fi >= n || next.se >= n) continue;
          if (board[next.fi][next.se] == 0) edge[now.fi][now.se] = true;
          if (board[next.fi][next.se] == 1) board[next.fi][next.se] = island, q.push(next);
        }
      }

      island++;
    }
  }

  int minlen = 1e9;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!edge[i][j]) continue;
      int from = board[i][j];
      vector<vector<bool>> vis(n, vector<bool>(n));
      queue<pair<pp, int>> q;
      q.push({{i, j}, 0});
      vis[i][j] = true;
      while (!q.empty())
      {
        pp nowp = q.front().fi;
        int nowl = q.front().se;
        q.pop();
        if (minlen < nowl)
          while (!q.empty()) q.pop();
        for (auto d : dp)
        {
          pp next = {nowp.fi + d.fi, nowp.se + d.se};
          if (next.fi < 0 || next.se < 0 || next.fi >= n || next.se >= n) continue;
          if (vis[next.fi][next.se]) continue;
          vis[next.fi][next.se] = true;
          if (board[next.fi][next.se] == 0) q.push({next, nowl + 1});
          else if (board[next.fi][next.se] != from)
          {
            minlen = min(minlen, nowl);
            while (!q.empty()) q.pop();
          }
        }
      }
    }
  }
  cout << minlen;

  return 0;
}
