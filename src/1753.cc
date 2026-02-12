// BOJ 1753
#include <algorithm>
#include <iostream>
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

int v, e, k, a, b, c;
vector<vector<pp>> adj; // fi: dest, se: cost

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  cin >> v >> e >> k;
  adj.resize(v + 1);
  for (int i = 0; i < e; i++) cin >> a >> b >> c, adj[a].push_back({b, c});

  return 0;
}
