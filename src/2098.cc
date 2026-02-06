// BOJ 2098
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

int initcity(int city) { return (1 << (city + 4)) | city; }
int viscity(int stat, int city)
{
  stat |= 1 << (city + 4);
  stat &= ~(0b1111);
  stat |= city;
  return stat;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vector<int>> w(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> w[i][j];

  // 도시 16개 -> 상태 2^16 = 65536개
  // 하위 4비트에 현재 도시 번호 저장 (0 = 0000b ~ 15 = 1111b)
  // 도시번호는 1에서 16이지만 편의상 -1해서 0에서 15
  // n번째 도시 방문함 -> n+4번째 비트 셋
  // 따라서 상태는 2^20 = 1048576가지
  // dp배열은 해당 상태로 갈수있는 가장 최소 비용을 저장
  // w의 값은 최대 100만인데, 도시가 16개면 dp는 최대 1600만 아닌가? 왜 오버플로우가 나지?
  constexpr int dp_novisit = 17000000;
  vector<int> dp(1048576, dp_novisit);
  queue<int> q;
  int ans = dp_novisit;
  int complete = 0;
  for (int i = 0; i < n; i++) complete |= 1 << (i + 4);

  q.push(initcity(0));
  dp[initcity(0)] = 0;

  while (!q.empty())
  {
    int now = q.front();
    q.pop();

    for (int i = 0; i < n; i++)
    {
      if (now & (1 << (i + 4))) continue;
      if (w[now & 0b1111][i] == 0) continue;

      int next = viscity(now, i);
      if (dp[next] == dp_novisit) q.push(next);
      dp[next] = min(dp[next], dp[now] + w[now & 0b1111][i]);
    }
  }

  for (int last = 1; last < n; last++)
  {
    if (w[last][0] == 0) continue;
    ans = min(ans, dp[complete | last] + w[last][0]);
  }

  cout << ans;

  return 0;
}
