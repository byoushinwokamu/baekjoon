// BOJ 2166
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pp;

ll cross_product(pp ab, pp ac)
{
  return ab.fi * ac.se - ab.se * ac.fi;
}

ll triangle_area(pp a, pp b, pp c)
{
  return cross_product({b.fi - a.fi, b.se - a.se}, {c.fi - a.fi, c.se - a.se});
}

istream &operator>>(istream &in, pp &p) { return in >> p.fi >> p.se; }
ostream &operator<<(ostream &out, pp &p) { return out << p.fi << ' ' << p.se << ' '; }

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  pp a, b, c;
  int n;
  cin >> n >> a >> b;

  ll area = 0;
  for (int i = 2; i < n; i++)
  {
    cin >> c;
#ifdef DEBUG
    cout << "Point A: " << a << '\n';
    cout << "Point B: " << b << '\n';
    cout << "Point C: " << c << '\n';
#endif
    area += triangle_area(a, b, c);
#ifdef DEBUG
    cout << "Area " << area << "\n\n";
#endif
    b = c;
  }

  cout.precision(1);
  cout << fixed << (abs(area) / 2.0);

  return 0;
}
