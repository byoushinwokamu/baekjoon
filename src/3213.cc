// BOJ 3213
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
  int n;
  cin >> n;
  string s;
  int q = 0, h = 0, t = 0;

  while (n--)
  {
    cin >> s;
    if (s == "1/4") q++;
    else if (s == "1/2") h++;
    else t++;
  }

  int p = 0;

  p += h / 2;
  h %= 2;

  while (t)
  {
    t--;
    if (q > 0) q--;
    p++;
  }

  if (h)
  {
    h--;
    if (q > 0) q--;
    if (q > 0) q--;
    p++;
  }

  p += q / 4;
  q %= 4;
  if (q) p++;

  cout << p;

  return 0;
}
