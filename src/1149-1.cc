// BOJ 1149-1
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int rr, gg, bb, r, g, b, q, w, e;
int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> q >> w >> e;
    rr = min(g, b) + q;
    gg = min(r, b) + w;
    bb = min(r, g) + e;
    r = rr, g = gg, b = bb;
  }
  cout << min({r, g, b});

  return 0;
}
