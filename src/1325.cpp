#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[10001];
bool vis[10001];
int hackable[10001];
int n, m, a, b, hmax;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[b].push_back(a);
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (hackable[i])
      continue;

    for (int j = 1; j <= n; j++)
      vis[j] = false;
    vis[i] = true;
    q.push(i);

    int h = 1;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int it : v[now]) {
        if (!vis[it]) {
          vis[it] = true;
          q.push(it);
          h++;
        }
      }
    }
    hackable[i] = h;
    hmax = hmax > h ? hmax : h;
  }

  for (int i = 1; i <= n; i++)
    if (hackable[i] == hmax)
      cout << i << ' ';

  return 0;
}