// BOJ 1197-k
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define vertex first
#define cost   second
#define fi     first
#define se     second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
typedef pair<pp, int> ppp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
istream &operator>>(istream &is, ppp &p) { return is >> p.vertex >> p.cost; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int v, e;
vector<int> parent;

int mind(int x)
{
  if (parent[x] == x) return x;
  return parent[x] = mind(parent[x]);
}

void onion(int x, int y)
{
  int rootx = mind(x), rooty = mind(y);
  if (rootx < rooty) parent[rooty] = rootx;
  else if (rootx > rooty) parent[rootx] = rooty;
}

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int a, b, c;
  cin >> v >> e;
  parent.resize(v + 1);
  for (int i = 1; i <= v; i++) parent[i] = i;
  vector<ppp> edge(e);
  for (int i = 0; i < e; i++)
    cin >> edge[i];
  sort(edge.begin(), edge.end(), [](const ppp &a, const ppp &b)
       { return a.cost < b.cost; });

  int te = 0; // 트리 안의 엣지 수
  ll mstcost = 0;
  for (int i = 0; i < e; i++)
  {
    if (te == v - 1) break;
    if (mind(edge[i].vertex.fi) == mind(edge[i].vertex.se)) continue;
    mstcost += edge[i].cost;
    te++;
    onion(edge[i].vertex.fi, edge[i].vertex.se);
  }
  cout << mstcost;

  return 0;
}
