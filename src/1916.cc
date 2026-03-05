// BOJ 1916
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define fi   first
#define se   second
#define cost fi
#define dest se

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<pp>> adj(n + 1);
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }

  int s, f;
  cin >> s >> f;

  constexpr int INF = 1e9;
  vector<int> dist(n + 1, INF);
  priority_queue<pp, vector<pp>, greater<pp>> pq;
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty())
  {
    int nowcost = pq.top().cost;
    int nowdest = pq.top().dest;
    pq.pop();

    if (dist[nowdest] < nowcost) continue;
    for (auto &edge : adj[nowdest])
    {
      int nextcost = nowcost + edge.cost;
      int nextdest = edge.dest;

      if (nextcost < dist[nextdest])
      {
        dist[nextdest] = nextcost;
        pq.push({nextcost, nextdest});
      }
    }
  }
  cout << dist[f];

  return 0;
}
