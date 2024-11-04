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
  int n, m, j, a;
  cin >> n >> m >> j;
  int l = 1, r = m, d = 0;
  while (j--) {
    cin >> a;
    if (l <= a && a <= r)
      ;
    else if (a < l)
      d += l - a, r -= l - a, l = a;
    else if (r < a)
      d += a - r, l -= r - a, r = a;
  }
  cout << d;

  return 0;
}
