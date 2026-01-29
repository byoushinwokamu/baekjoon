// BOJ 1240
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

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m;
  int a, b, c;
  cin >> n >> m;
  vector<vector<pp>> adj(n + 1); // fi: connected node, se: distance
  vector<vector<int>> dd(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n - 1; i++)
  {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    if (dd[a][b])
    {
      cout << dd[a][b] << '\n';
      continue;
    }

    queue<pp> q; // fi: now node, se: dist
    vector<bool> vis(n + 1);
    q.push({a, 0});
    vis[a] = true;
    while (!q.empty())
    {
      int now = q.front().fi, dist = q.front().se;
      q.pop();
      if (now == b)
      {
        dd[a][b] = dd[b][a] = dist;
        cout << dist << '\n';
        break;
      }

      for (auto p : adj[now])
      {
        if (vis[p.fi]) continue;
        vis[p.fi] = true;
        q.push({p.fi, p.se + dist});
      }
    }
  }

  return 0;
}
