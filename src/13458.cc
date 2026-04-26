// BOJ 13458
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

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n, b, c;
  ll s = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> b >> c;
  for (int i = 0; i < n; i++)
  {
    s++, a[i] -= b;
    s += (a[i] > 0) ? (a[i] / c + ((a[i] % c) ? 1 : 0)) : 0;
  }
  cout << s;

  return 0;
}
