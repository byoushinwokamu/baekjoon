// BOJ 17404
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int cost[1000][3];
int best[1000][3][3]; // fi: addr, se: col, th: col of [0]

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  best[0][0][0] = cost[0][0], best[0][1][1] = cost[0][1], best[0][2][2] = cost[0][2];
  best[0][0][1] = best[0][0][2] = 1001;
  best[0][1][0] = best[0][1][2] = 1001;
  best[0][2][0] = best[0][2][1] = 1001;
  for (int i = 1; i < n; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      best[i][0][k] = cost[i][0] + min(best[i - 1][1][k], best[i - 1][2][k]);
      best[i][1][k] = cost[i][1] + min(best[i - 1][0][k], best[i - 1][2][k]);
      best[i][2][k] = cost[i][2] + min(best[i - 1][0][k], best[i - 1][1][k]);
    }
  }
  cout << min({best[n - 1][0][1], best[n - 1][0][2],
               best[n - 1][1][0], best[n - 1][1][2],
               best[n - 1][2][0], best[n - 1][2][1]});

  return 0;
}
