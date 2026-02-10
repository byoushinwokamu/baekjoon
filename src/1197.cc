// BOJ 1197
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

vector<vector<pp>> adj; // fi: destination, se: cost

typedef struct
{
  bool operator()(const pp &a, const pp &b)
  {
    return a.se > b.se;
  }
} compare;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int v, e, a, b, c;
  cin >> v >> e;
  adj.resize(v + 1);
  for (int i = 0; i < e; i++)
  {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  ll cost = 0;
  int tv = 1; // tree에 포함된 vertex 수
  priority_queue<pp, vector<pp>, compare> pq;
  vector<bool> vis(v + 1);
  vis[1] = true;
  for (auto p : adj[1]) pq.push(p);

  while (tv < v)
  {
    pp now = pq.top();
    pq.pop();
    if (vis[now.fi]) continue;
    vis[now.fi] = true;
    cost += now.se;
    for (auto p : adj[now.fi])
      if (!vis[p.fi]) pq.push(p);
    tv++;
  }
  cout << cost;

  return 0;
}
