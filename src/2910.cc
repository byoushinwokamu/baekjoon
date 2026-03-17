// BOJ 2910
#include <algorithm>
#include <iostream>
#include <map>
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

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n, c, a;
  cin >> n >> c;
  map<int, pp> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if (m.count(a)) m[a].se++;
    else m[a] = {i, 1};
  }
  vector<pair<int, pp>> v(m.begin(), m.end());
  sort(v.begin(), v.end(), [](const pair<int, pp> &a, const pair<int, pp> &b)
       {
         return a.se.se != b.se.se ? a.se.se > b.se.se : a.se.fi < b.se.fi;
       });

  for (auto p : v)
    for (int i = p.se.se; i > 0; i--)
      cout << p.fi << ' ';

  return 0;
}
