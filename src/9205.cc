#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int dist(const pp &p1, const pp &p2) {
  return abs(p1.fi - p2.fi) + abs(p1.se - p2.se);
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t, n, x, y;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    pp home = {x, y};
    vector<pp> conv(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      conv[i] = {x, y};
    }
    cin >> x >> y;
    pp ptpt = {x, y};
  }

  return 0;
}
