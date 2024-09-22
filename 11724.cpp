#include <iostream>
#include <queue>

using namespace std;

int adj[1000][1000];
int vis[1000];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[--u][--v]++, adj[v][u]++;
  }

  queue<int> q;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i])
      continue;
    q.push(i);
    cnt++;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      vis[now]++;
      for (int i = 0; i < n; i++)
        if (!vis[i] && adj[now][i])
          q.push(i), vis[i]++;
    }
  }
  cout << cnt;
  return 0;
}