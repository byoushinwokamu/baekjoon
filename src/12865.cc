// BOJ 12865
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define fi     first
#define se     second
#define weight fi
#define value  se

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<pp> item(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> item[i].weight >> item[i].value;
  }

  vector<vector<int>> dp(n + 1, vector<int>(k + 1));
  for (int i = 1; i <= n; i++)
  {
    for (int w = 1; w <= k; w++)
    {
      if (item[i].weight <= w)
        dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - item[i].weight] + item[i].value);
      else
        dp[i][w] = dp[i - 1][w];
    }
  }
  cout << dp[n][k];

  return 0;
}
