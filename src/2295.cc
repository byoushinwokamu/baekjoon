// BOJ 2295
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
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
  vector<int> v(n);
  vector<int> twosum(n * n);
  for (int i = 0; i < n; i++) cin >> v[i];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      twosum[i * n + j] = v[i] + v[j];
  sort(twosum.begin(), twosum.end());
  // unordered_set<int> u(v.begin(), v.end());

  int res = 0;
  for (auto z = v.begin(); z != v.end(); z++)
  {
    for (auto k = v.begin(); k != v.end(); k++)
    {
      if (binary_search(twosum.begin(), twosum.end(), *k - *z))
      {
        res = max(res, *k);
      }
    }
  }
  cout << res;

  return 0;
}
