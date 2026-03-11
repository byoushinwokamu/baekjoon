// BOJ 21940
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

int dp[201][201];

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);

  int n, m, a, b, c, k;
  cin >> n >> m;

  constexpr int inf = 1e9;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dp[i][j] = i == j ? 0 : inf;
  // dp[i][j] = inf;

  for (int i = 0; i < m; i++)
  {
    cin >> a >> b >> c;
    dp[a][b] = min(dp[a][b], c);
  }

  cin >> k;
  vector<int> living(k);
  for (int i = 0; i < k; i++) cin >> living[i];

  for (int j = 1; j <= n; j++)
    for (int i = 1; i <= n; i++)
      for (int k = 1; k <= n; k++)
        dp[i][k] = min(dp[i][k], dp[i][j] + dp[j][k]);

  vector<pp> res; // fi: 왕복거리, se: 도시번호
  for (int city = 1; city <= n; city++)
  {
    int tmax = 0;
    for (auto home : living)
      tmax = max(tmax, dp[home][city] + dp[city][home]);
    res.push_back({tmax, city});
  }
  sort(res.begin(), res.end());

  int wb = res.front().fi;
  for (auto r : res)
  {
    if (wb != r.fi) break;
    cout << r.se << ' ';
  }

  return 0;
}
