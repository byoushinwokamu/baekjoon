#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll n, x, a, i, d = 0;
  cin >> n >> x;
  for (ll q = 0; q <= n; q++) {
    cin >> a >> i;
    d *= x;
    d += a;
    d %= (ll)1e9 + 7;
  }
  cout << d;

  return 0;
}
