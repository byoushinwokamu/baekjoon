// BOJ 2342
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int dp[5][5][100005]; // 왼발, 오른발, 노트번호. 숫자: 최소힘

int getpow(int a, int b)
{
  if (b == 0) return 99;
  if (a == b) return 1;
  if (a == 0) return 2;
  if (a - b == 2 || b - a == 2) return 4;
  return 3;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  for (auto &ddp : dp)
    for (auto &dddp : ddp)
      fill(dddp, dddp + 100002, 999999);

  int note, i;
  cin >> note;
  dp[0][0][0] = 0;
  for (i = 1; note != 0; i++)
  {
    for (int lft = 0; lft < 5; lft++) // 오른발로 밟는 경우
    {
      if (note == lft) continue; // 왼발이 노트에 있을 수 없음
      for (int rbef = 0; rbef < 5; rbef++)
        dp[lft][note][i] = min(dp[lft][note][i], dp[lft][rbef][i - 1] + getpow(rbef, note));
    }
    for (int rht = 0; rht < 5; rht++) // 왼발로 밟는 경우
    {
      if (note == rht) continue; // 오른발이 노트에 있을 수 없음
      for (int lbef = 0; lbef < 5; lbef++)
        dp[note][rht][i] = min(dp[note][rht][i], dp[lbef][rht][i - 1] + getpow(lbef, note));
    }

    cin >> note;
  }

  int minpow = __INT32_MAX__;
  for (auto &ddp : dp)
    for (auto &dddp : ddp)
    {
      minpow = min(minpow, dddp[i - 1]);
    }

  cout << minpow;

  return 0;
}
