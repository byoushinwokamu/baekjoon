// BOJ 12865-1
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
pp item[101];

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> item[i].ww >> item[i].vv;

  for (int i = 1; i <= n; i++)
  {
    for (int w = k; w >= 1; w--)
    {
      if (item[i].ww <= w)
        dp[w] = max(dp[w], dp[w - item[i].ww] + item[i].vv);
    }
  }
  cout << dp[k];

  return 0;
}
