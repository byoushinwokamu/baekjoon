#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

ll n, s;
ll summ = 0, cnt = 0;
vector<ll> v;

void dfs(ll last) {
  for (ll i = last + 1; i < n; i++) {
    summ += v[i];
    if (summ == s)
      cnt++;
    dfs(i);
    summ -= v[i];
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> s;
  v.resize(n);
  for (ll i = 0; i < n; i++)
    cin >> v[i];

  dfs(-1);
  cout << cnt;

  return 0;
}
