// BOJ 1106-dp
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second
#define ww fi
#define vv se

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int dp[100001];
pp city[21];

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int c, n;
  cin >> c >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> city[i].ww >> city[i].vv;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int w = 1; w <= 100001; w++)
    {
      if (city[i].ww <= w)
        dp[w] = max(dp[w], dp[w - city[i].ww] + city[i].vv);
    }
  }

  for (int w = 0;; w++)
  {
    if (dp[w] >= c)
    {
      cout << w;
      return 0;
    }
  }
  return 0;
}
