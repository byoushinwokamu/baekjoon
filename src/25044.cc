#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int d = 0;

pp operator+(const pp &p1, const pp &p2) {
  pp res = {p1.fi + p2.fi, p1.se + p2.se};
  if (res.se >= 60)
    res.se -= 60, res.fi++;
  if (res.fi >= 24)
    d++, res.fi -= 24;
  return res;
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  vector<vector<pp>> v(1001);
  int n, k, a = 0;
  cin >> n >> k;

  pp t = {15, 0};
  while (d <= 1000) {
    v[d].push_back(t);
    a++;
    t = t + make_pair((a == 3 ? 18 : 3), (a == 3 ? k : 0));
    a %= 3;
  }
  cout << v[n].size() << '\n';
  for (auto p : v[n]) {
    if (p.fi < 10)
      cout << '0';
    cout << p.fi << ':';
    if (p.se < 10)
      cout << '0';
    cout << p.se << '\n';
  }

  return 0;
}
