#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  ll n, r, s = 0;
  cin >> n >> r;
  n -= r;
  ll rn = sqrt(n);
  for (ll i = 1; i <= rn; i++) {
    if (n % i == 0) {
      if (i > r)
        s += i;
      if (i != n / i && n / i > r)
        s += n / i;
    }
  }
  cout << s;

  return 0;
}