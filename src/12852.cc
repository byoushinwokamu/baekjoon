// BOJ 12852
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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
  vector<pp> dp(1000001); // fi: 연산의 최솟값, se: 그 최솟값으로 오기 전 수
  dp[n] = {0, -1};

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
      if (dp[nn].fi == 0 || dp[nn].fi > dp[now].fi + 1) dp[nn] = {dp[now].fi + 1, now}, q.push(nn);
      if (nn == 1)
        while (!q.empty()) q.pop();
    }
  }

  stack<int> st;

  for (int now = 1; now != -1; now = dp[now].se)
  {
    st.push(now);
  }
  cout << dp[1].fi << '\n';
  while (!st.empty()) cout << st.top() << ' ', st.pop();

  return 0;
}
