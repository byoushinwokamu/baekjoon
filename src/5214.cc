// BOJ 5214
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

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n, k, m, a;
  cin >> n >> k >> m;
  int gsize = n + m;
  vector<vector<int>> adj(gsize);
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < k; j++)
    {
      cin >> a;
      a--;
      adj[a].push_back(i + n);
      adj[i + n].push_back(a);
    }
  }

  queue<pp> q;
  q.push({0, 1});
  vector<bool> vis(gsize);
  while (!q.empty())
  {
    int now = q.front().fi;
    int len = q.front().se;
    q.pop();

    if (now == n - 1)
    {
      cout << len / 2 + 1;
      return 0;
    }

    for (auto next : adj[now])
    {
      if (vis[next]) continue;
      vis[next] = true;
      q.push({next, len + 1});
    }
  }
  cout << -1;

  return 0;
}
