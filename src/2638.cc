// BOJ 2638
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, m, nm, cheese;
pp operator+(const pp &a, const pp &b) { return {a.fi + b.fi, a.se + b.se}; }
int conv(const pp &p) { return p.fi * m + p.se; }
bool valid(const pp &p) { return p.fi >= 0 && p.se >= 0 && p.fi < n && p.se < m; }
constexpr pp dp[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m;
  nm = n * m;
  vector<int> board(nm);
  for (int i = 0; i < nm; i++)
  {
    cin >> board[i];
    if (board[i] == 1) cheese++;
  }
  int t;

  for (t = 1; cheese; t++)
  {
    queue<pp> q;
    vector<int> vis(nm);

    q.push({0, 0});
    vis[0] = 1;
    while (!q.empty())
    {
      pp now = q.front();
      q.pop();

      for (auto d : dp)
      {
        pp next = d + now;
        if (!valid(next)) continue;
        if (board[conv(next)] == 0)
        {
          if (vis[conv(next)]++ == 0) q.push(next);
        }
        else
        {
          if (vis[conv(next)]++ == 1) cheese--, board[conv(next)] = 0;
        }
      }
    }
  }
  cout << t - 1;

  return 0;
}
