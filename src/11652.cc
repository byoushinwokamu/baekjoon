// BOJ 11652
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
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  ll cur = v.front(), maxcur = v.front();
  int cnt = 0, maxcnt = 0;
  for (auto i : v)
  {
    if (cur == i)
    {
      if (++cnt > maxcnt) maxcur = cur, maxcnt = cnt;
    }
    else cur = i, cnt = 1;
  }
  cout << maxcur;

  return 0;
}
