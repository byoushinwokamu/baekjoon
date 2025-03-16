// BOJ 13023
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, m, aa;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int depth, int now) {
  if (depth == 5) {
    cout << 1;
    exit(0);
  }
  if (depth == 0) {
    for (int i = 0; i < n; i++) {
      aa = i;
      vis[i] = true;
      dfs(depth + 1, i);
      vis[i] = false;
    }
  } else {
    for (auto i : adj[now]) {
      if (vis[i])
        continue;
      vis[i] = true;
      dfs(depth + 1, i);
      vis[i] = false;
    }
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m;
  adj.resize(n);
  vis.resize(n);

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, 0);
  cout << 0;

  return 0;
}
