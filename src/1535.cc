// BOJ 1535
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

int dp[101];
pp thx[101];

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> thx[i].ww;
  for (int i = 1; i <= n; i++) cin >> thx[i].vv;
  for (int i = 1; i <= n; i++)
  {
    for (int w = 100; w >= 1; w--)
    {
      if (thx[i].ww <= w)
        dp[w] = max(dp[w], dp[w - thx[i].ww] + thx[i].vv);
    }
  }
  cout << dp[99];

  return 0;
}
