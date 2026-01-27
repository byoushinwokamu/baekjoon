// BOJ 1463
#include <algorithm>
#include <iostream>
#include <queue>
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
  vector<int> dp(1000001); // 연산의 최솟값
  dp[n] = 0;

  queue<int> q;
  q.push(n);
  while (!q.empty())
  {
    int now = q.front();
    q.pop();
    int next[3] = {(now % 3) ? 0 : (now / 3), (now % 2) ? 0 : (now / 2), now - 1};
    for (auto nn : next)
    {
      if (nn <= 0) continue;
      if (dp[nn] == 0 || dp[nn] > dp[now] + 1) dp[nn] = dp[now] + 1, q.push(nn);
      if (nn == 1)
        while (!q.empty()) q.pop();
    }
  }

  cout << dp[1] << '\n';

  return 0;
}
