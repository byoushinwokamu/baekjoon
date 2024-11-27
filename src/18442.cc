#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

ll v, p, l;
ll mindis = ~(1UL << 63);

vector<ll> vil;
vector<ll> ucg;
vector<ll> ucg_min;

ll dist(ll x, ll y) { return min(abs(x - y), l - abs(x - y)); }

void dfs(int depth, ll last) {
  if (depth == p) {
    ll dis = 0;
    for (auto vv : vil) {
      ll localdis = ~(1UL << 63);
      for (auto uu : ucg) {
        localdis = min(localdis, dist(vv, uu));
      }
      dis += localdis;
    }
    if (mindis > dis)
      mindis = dis, ucg_min = ucg;
    return;
  }
  for (ll i = last + 1; i < v; i++) {
    ucg[depth] = vil[i];
    dfs(depth + 1, i);
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> v >> p >> l;
  vil.resize(v);
  ucg.resize(p);
  ucg_min.resize(p);
  for (ll i = 0; i < v; i++)
    cin >> vil[i];

  dfs(0, -1);
  cout << mindis << '\n';
  for (auto i : ucg_min)
    cout << i << ' ';

  return 0;
}
