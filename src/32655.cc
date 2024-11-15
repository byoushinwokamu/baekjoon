#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, ll> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pp>> adj(n);
  vector<pp> ext(n);
  vector<bool> vis(n);
  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj[a - 1].push_back({b - 1, c});
    adj[b - 1].push_back({a - 1, c});
  }
  int x, e;
  cin >> x;
  for (int i = 1; i <= x; i++) {
    cin >> e;
    ext[e - 1] = {k * (i - 1), k * i - 1};
  }

  queue<pp> q;
  vis[0] = true;
  q.push({0, 0});
  ll opt = __INT64_MAX__;
  while (!q.empty()) {
    int now = q.front().fi;
    ll tim = q.front().se;
    q.pop();
    if (ext[now].se) {
      ll tt = tim % ((ll)x * k);
      if (ext[now].fi <= tt && tt <= ext[now].se) {
        opt = min(opt, tim);
      } else if (tt < ext[now].fi) {
        opt = min(opt, tim + (ext[now].fi - tt));
      } else {
        opt = min(opt,
                  (tim / (ll)(x * k) * x * k) + (ll)x * k + (ext[now].fi - tt));
      }
    }
    for (auto a : adj[now]) {
      if (vis[a.fi])
        continue;
      vis[a.fi] = true;
      q.push({a.fi, tim + a.se});
    }
  }
  cout << opt;

  return 0;
}
