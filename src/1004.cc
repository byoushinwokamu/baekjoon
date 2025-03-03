// BOJ 1004
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<double, double> pp;

double dist(pp a, pp b) {
  return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

bool inner(pp p, pp center, double rad) { return dist(p, center) <= rad; }

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    pp st, de;
    cin >> st.fi >> st.se >> de.fi >> de.se;
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
      pp ct;
      double r;
      cin >> ct.fi >> ct.se >> r;
      if (inner(st, ct, r) != inner(de, ct, r))
        cnt++;
    }
    cout << cnt << '\n';
  }

  return 0;
}
