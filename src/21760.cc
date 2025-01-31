// BOJ 21760
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
  int t;
  cin >> t;
  while (t--) {
    ll n, m, k, d;
    cin >> n >> m >> k >> d;
    ll g = 0;
    ll g1 = ((m - 1) * k + (n - 1) * m) * n * m / 2;
    int b;
    for (b = 1; g <= d; b++) {
      g += g1;
    }
    if (g == g1)
      cout << "-1\n";
    else
      cout << g - g1 << '\n';
  }

  return 0;
}
