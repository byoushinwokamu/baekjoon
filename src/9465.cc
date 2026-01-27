// BOJ 9465
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<pp> point(n);
    for (int i = 0; i < n; i++) cin >> point[i].fi;
    for (int i = 0; i < n; i++) cin >> point[i].se;
    vector<tuple<int, int, int>> dp(n); // 0: 안뗀거 1: 위에뗀거 2: 아래뗀거

    get<0>(dp[0]) = 0;
    get<1>(dp[0]) = point[0].fi;
    get<2>(dp[0]) = point[0].se;

    for (int i = 1; i < n; i++)
    {
      get<0>(dp[i]) = max({get<0>(dp[i - 1]), get<1>(dp[i - 1]), get<2>(dp[i - 1])});
      get<1>(dp[i]) = max({get<0>(dp[i - 1]), get<2>(dp[i - 1])}) + point[i].fi;
      get<2>(dp[i]) = max({get<0>(dp[i - 1]), get<1>(dp[i - 1])}) + point[i].se;
    }
    cout << max({get<0>(dp[n - 1]), get<1>(dp[n - 1]), get<2>(dp[n - 1])}) << '\n';
  }

  return 0;
}
