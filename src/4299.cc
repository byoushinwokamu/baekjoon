// BOJ 4299
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
  int a, b, n, m;
  cin >> a >> b;
  n = (a + b) / 2;
  m = (a - b) / 2;
  if (m < 0 || (a + b) & 1)
    cout << -1;
  else
    cout << n << ' ' << m;

  return 0;
}
