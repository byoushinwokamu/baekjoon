#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<vector<pp>> adj(100001);
vector<bool> vis(100001);
int v, a, b, c, mdis, farnode;

void dfs(int now, int dis) {
  if (mdis < dis) {
    mdis = dis;
    farnode = now;
  }
  for (auto a : adj[now]) {
    if (vis[a.fi])
      continue;
    vis[a.fi] = true;
    dfs(a.fi, a.se + dis);
    vis[a.fi] = false;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> v;
  for (int i = 0; i < v; i++) {
    cin >> a;
    cin >> b;
    while (b != -1) {
      cin >> c;
      adj[a].push_back({b, c});
      cin >> b;
    }
  }
  vis[1] = true;
  dfs(1, 0);
  vis[1] = false;

  mdis = 0;
  vis[farnode] = true;
  dfs(farnode, 0);
  cout << mdis;

  return 0;
}