// BOJ 1753
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second

#define cost fi
#define dest se

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int v, e, k, a, b, c;

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  cin >> v >> e >> k;
  vector<vector<pp>> adj(v + 1); // fi: dest, se: cost

  for (int i = 0; i < e; i++)
  {
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }

  constexpr int INF = 1e9;
  vector<int> dist(v + 1, INF);                   // 출발점으로부터의 최단거리
  priority_queue<pp, vector<pp>, greater<pp>> pq; // mst에 없는 vertex들
  dist[k] = 0;                                    // 출발점은 거리 0
  pq.push({0, k});

  while (!pq.empty())
  {
    int nowcost = pq.top().cost;
    int nownode = pq.top().dest;
    pq.pop();

    // 큐에서 꺼낸 거리가 최단거리보다 크면 처리된 과거 데이터이므로 무시
    if (dist[nownode] < nowcost) continue;

    // 현재 정점과 직접 연결된 정점들 탐색
    for (auto &edge : adj[nownode])
    {
      int nextcost = edge.cost + nowcost;
      int nextnode = edge.dest;

      // 더 짧은 경로가 있으면 갱신하고 삽입
      if (nextcost < dist[nextnode])
      {
        dist[nextnode] = nextcost;
        pq.push({nextcost, nextnode});
      }
    }
  }
  for (int i = 1; i <= v; i++)
    if (dist[i] != INF)
      cout << dist[i] << '\n';
    else
      cout << "INF\n";

  return 0;
}
