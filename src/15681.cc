// BOJ 15681
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, r, q;
int nodes[100001];
vector<vector<int>> adj(100001);

int getnodes(int root, int bef)
{
  // cout << "NOW: " << root << endl;
  if (nodes[root]) return nodes[root];
  int nod = 1;
  for (auto child : adj[root])
    if (child != bef)
      nod += getnodes(child, root);
  nodes[root] = nod;
  return nod;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int u, v;
  cin >> n >> r >> q;
  for (int i = 0; i < n - 1; i++)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // dfs
  getnodes(r, 0);

  for (int i = 0; i < q; i++)
  {
    cin >> u;
    cout << nodes[u] << '\n';
  }

  return 0;
}
