// BOJ 1707
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
  int k, v, e;
  cin >> k;
  while (k--)
  {
    cin >> v >> e;
    vector<vector<int>> adj(v + 1);
    for (int i = 0; i < e; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    //
    bool ibun = true;
    queue<pp> q; // fi: node, se: level
    vector<int> level(v + 1);
    for (int st = 1; st <= v; st++)
    {
      if (level[st]) continue;
      q.push({st, 1});
      level[st] = 1;
      while (!q.empty())
      {
        int nownode = q.front().fi;
        int nowlevel = q.front().se;
        q.pop();
        for (auto nextnode : adj[nownode])
        {
          if (level[nextnode])
          {
            if (((1 & nowlevel) == (1 & level[nextnode])))
              ibun = false;
          }
          else
          {
            q.push({nextnode, nowlevel + 1});
            level[nextnode] = nowlevel + 1;
          }
        }
      }
    }
    cout << (ibun ? "YES\n" : "NO\n");
  }

  return 0;
}
