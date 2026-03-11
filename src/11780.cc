// BOJ 11780
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

int dp[101][101];
vector<int> route[101][101];

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  constexpr int inf = 1e9;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dp[i][j] = ((i == j) ? 0 : inf), route[i][j].push_back(i);

  int a, b, c;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    if (dp[a][b] == inf) route[a][b].push_back(b);
    dp[a][b] = min(c, dp[a][b]);
  }

  for (int j = 1; j <= n; j++)
    for (int i = 1; i <= n; i++)
      for (int k = 1; k <= n; k++)
      {
        if (dp[i][k] > dp[i][j] + dp[j][k])
        {
          dp[i][k] = dp[i][j] + dp[j][k];
          route[i][k] = route[i][j];
          // route[i][k].pop_back();
          route[i][k].insert(route[i][k].end(), route[j][k].begin() + 1, route[j][k].end());
        }
      }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      cout << (dp[i][j] == inf ? 0 : dp[i][j]) << ' ';
    cout << '\n';
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (dp[i][j] == inf || dp[i][j] == 0) cout << 0;
      else
      {
        cout << route[i][j].size() << ' ';
        for (auto r : route[i][j]) cout << r << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}
