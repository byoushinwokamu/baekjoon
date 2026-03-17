// BOJ 15688
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
  int n, a;
  cin >> n;
  vector<int> v(2000001);
  while (n--) cin >> a, v[a + 1000000]++;
  for (int i = v.size() - 1; i >= 0; i--)
    for (int j = v[i]; j > 0; j--) cout << i - 1000000 << '\n';

  return 0;
}
