// BOJ 11049
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int dp[500][500]; // fi: start, se: end
pp mat[500];

int dynamic_busan(int st, int en)
{
  int res = dp[st][en];
  if (res) return res;
  if (st == en) return 0;
  if (st + 1 == en) return (dp[st][en] = mat[st].fi * mat[st].se * mat[en].se);

  res = __INT32_MAX__;
  for (int cur = st + 1; cur <= en; cur++)
    res = min(res, dynamic_busan(st, cur - 1) + dynamic_busan(cur, en) + mat[st].fi * mat[cur].fi * mat[en].se);
  return (dp[st][en] = res);
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n; // 곱셈 기호는 (n - 1)개
  for (int i = 0; i < n; i++) cin >> mat[i].fi >> mat[i].se;
  cout << dynamic_busan(0, n - 1);

  return 0;
}
