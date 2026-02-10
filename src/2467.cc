// BOJ 2467
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());

  int zeroest = 2'000'000'009;
  int ansl = 0, ansr = n - 1;

  for (int lc = 0; lc < n - 1; lc++)
  {
    int rc = lower_bound(v.begin() + lc + 1, v.end(), -v[lc]) - v.begin();
    if (rc == n) rc--;
    if (rc != lc + 1 && abs(v[lc] + v[rc]) > abs(v[lc] + v[rc - 1])) rc--;
    if (zeroest > abs(v[lc] + v[rc])) zeroest = abs(v[lc] + v[rc]), ansl = lc, ansr = rc;
    // cout << "l " << lc << " r " << rc << " z " << zeroest << '\n';
  }

  cout << v[ansl] << ' ' << v[ansr];

  return 0;
}
