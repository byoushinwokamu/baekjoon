#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define first fi
#define second se
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<int>> v(n + 1);
  vector<int> parent(n + 1);
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  vector<bool> vis(n + 1);
  queue<int> q;
  vis[1] = true;
  q.push(1);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto i : v[now]) {
      if (vis[i])
        continue;
      vis[i] = true;
      parent[i] = now;
      q.push(i);
    }
  }
  for (int i = 2; i <= n; i++)
    cout << parent[i] << '\n';

  return 0;
}