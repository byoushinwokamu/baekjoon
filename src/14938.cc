// BOJ 14938
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

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n, m, r, t, a, b, l;
  cin >> n >> m >> r;
  constexpr int inf = 1e9;
  vector<vector<int>> adj(n, vector<int>(n, inf));
  vector<int> item(n);
  for (int i = 0; i < n; i++)
    cin >> item[i], adj[i][i] = 0;
  for (int i = 0; i < r; i++)
  {
    cin >> a >> b >> l;
    adj[a - 1][b - 1] = adj[b - 1][a - 1] = l;
  }

  // Floyd-Warshall
  for (int j = 0; j < n; j++)
    for (int i = 0; i < n; i++)
      for (int k = 0; k < n; k++)
        adj[i][k] = min(adj[i][k], adj[i][j] + adj[j][k]), adj[k][i] = adj[i][k];

  int maxgot = 0;
  for (int st = 0; st < n; st++)
  {
    int got = 0;
    for (int place = 0; place < n; place++)
      if (adj[st][place] <= m) got += item[place];
    maxgot = max(got, maxgot);
  }
  cout << maxgot;

  return 0;
}
