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
vector<int> vis(100001);
int n, a, b, c, mdis, farnode;

void dfs(int now, int dis) {
  int cnt = 0;
  for (auto a : adj[now]) {
    if (vis[a.fi])
      continue;
    cnt++;
    vis[a.fi] = true;
    dfs(a.fi, a.se + dis);
    vis[a.fi] = false;
  }
  if (!cnt && mdis < dis) {
    mdis = dis;
    farnode = now;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
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
