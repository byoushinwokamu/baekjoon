#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second
typedef long long ll;

using namespace std;

vector<vector<pair<int, int>>> adj(10001);
vector<bool> isleaf(10001);
int n, a, b, c;
int maxdis = 0;
int disnow = 0;

void finddis(int now, int from) {
  for (auto a : adj[now]) {
    if (a.fi == from)
      continue;
    disnow += a.se;
    finddis(a.fi, now);
    disnow -= a.se;
  }

  if (isleaf[now]) {
    maxdis = max(maxdis, disnow);
    return;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    isleaf[a] = false, isleaf[b] = true;
  }
  isleaf[1] = true;

  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 1)
      finddis(i, 0);
  }

  cout << maxdis << '\n';

  return 0;
}
