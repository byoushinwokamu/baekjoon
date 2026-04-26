// BOJ 32250
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
  vector<pp> v(n);
  v[0] = {0, n};
  for (int i = 1; i < n; i++)
  {
  }

  return 0;
}
