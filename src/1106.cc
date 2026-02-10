// BOJ 1106
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
int c, n;
int mincost = __INT32_MAX__;
vector<pp> v;

void dfs(int costidx, pp now)
{
  if (costidx == n) return;
  int cnt = 0;
  while (now.se < c) cnt++, now.fi += v[costidx].fi, now.se += v[costidx].se;
  mincost = min(mincost, now.fi);
  while (cnt--)
  {
    now.fi -= v[costidx].fi, now.se -= v[costidx].se;
    dfs(costidx + 1, now);
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> c >> n;
  v.resize(n); // fi: cost, se: gain
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end(), [](const pp &a, const pp &b)
       { return a.se > b.se; });
  dfs(0, {0, 0});
  cout << mincost;

  return 0;
}
