#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll n, k, c = 0;
  vector<ll> v(100001);
  cin >> n;
  v[0] = 0;
  for (ll i = 1; i <= n; i++)
    cin >> v[i];
  cin >> k;
  if (n == 1) {
    cout << (k == v[1] ? 'T' : 'F');
  } else {
    for (ll i = 1; i < n; i++) {
      if (v[i] > k * i && v[i + 1] <= k * (i + 1))
        c++;
      else if (v[i] < k * i && v[i + 1] >= k * (i + 1))
        c++;
    }
    cout << (c ? 'T' : 'F');
  }

  return 0;
}
