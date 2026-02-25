// BOJ 12873
#include <algorithm>
#include <iostream>
#include <queue>
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
  vector<int> v;
  for (int i = 1; i <= n; i++) v.push_back(i);
  ll cur = 0;
  for (ll t = 1; t < n; t++)
  {
    ll ttt = t * t * t;
    cur += ttt - 1;
    cur %= v.size();
    v.erase(v.begin() + cur);
  }
  cout << v[0];

  return 0;
}
