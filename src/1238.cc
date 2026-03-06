// BOJ 1238
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
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<pp>> adjf(n + 1);
  vector<vector<pp>> adjr(n + 1);
  for (int i = 0; i < m; i++)
  {
    int from, to, tim;
    cin >> from >> to >> tim;
    adjf[from].push_back({tim, to});
    adjr[to].push_back({tim, from});
  }

  constexpr int INF = 1e9;
  priority_queue<pp, vector<pp>, greater<pp>> pq;
  vector<int> distf(n + 1, INF);
  distf[x] = 0;
  vector<int> distr(n + 1, INF);
  distr[x] = 0;

  pq.push({0, x});
  while (!pq.empty())
  {
    int nowcost = pq.top().cost;
    int nowdest = pq.top().dest;
    pq.pop();

    if (nowcost > distf[nowdest])
      continue;
    for (auto &edge : adjf[nowdest])
    {
      int nextcost = nowcost + edge.cost;
      int nextdest = edge.dest;
      if (nextcost < distf[nextdest])
      {
        distf[nextdest] = nextcost;
        pq.push({nextcost, nextdest});
      }
    }
  }

  pq.push({0, x});
  while (!pq.empty())
  {
    int nowcost = pq.top().cost;
    int nowdest = pq.top().dest;
    pq.pop();

    if (nowcost > distr[nowdest])
      continue;
    for (auto &edge : adjr[nowdest])
    {
      int nextcost = nowcost + edge.cost;
      int nextdest = edge.dest;
      if (nextcost < distr[nextdest])
      {
        distr[nextdest] = nextcost;
        pq.push({nextcost, nextdest});
      }
    }
  }

  int maxt = 0;
  for (int i = 1; i <= n; i++)
  {
    maxt = max(maxt, distf[i] + distr[i]);
  }
  cout << maxt;

  return 0;
}
