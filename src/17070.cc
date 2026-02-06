// BOJ 17070
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, a;
int dp[3][16][16]; // 0: 가로, 1: 세로, 2: 대각선
int board[16][16];

int backtrack(pp p, int dir)
{
  if (p.fi < 0 || p.se < 0) return 0;

  int res = dp[dir][p.fi][p.se];
  if (res) return res;

  if (dir == 0) // 가로
  {
    if (board[p.fi][p.se] == 1) return 0;
    // 가로 -> 가로
    res += backtrack({p.fi, p.se - 1}, 0);
    // 대각선 -> 가로
    res += backtrack({p.fi, p.se - 1}, 2);
  }
  else if (dir == 1) // 세로
  {
    if (board[p.fi][p.se] == 1) return 0;
    // 세로 -> 세로
    res += backtrack({p.fi - 1, p.se}, 1);
    // 대각선 -> 세로
    res += backtrack({p.fi - 1, p.se}, 2);
  }
  else if (dir == 2) // 대각선
  {
    if (board[p.fi][p.se] == 1 || board[p.fi - 1][p.se] == 1 || board[p.fi][p.se - 1] == 1) return 0;
    // 가로 -> 대각선
    res += backtrack({p.fi - 1, p.se - 1}, 0);
    // 세로 -> 대각선
    res += backtrack({p.fi - 1, p.se - 1}, 1);
    // 대각선 -> 대각선
    res += backtrack({p.fi - 1, p.se - 1}, 2);
  }
  dp[dir][p.fi][p.se] = res;
  return res;
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, a;
  cin >> n;
  for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++)
      cin >> board[r][c];

  dp[0][0][1] = 1;
  cout << backtrack({n - 1, n - 1}, 0) + backtrack({n - 1, n - 1}, 1) + backtrack({n - 1, n - 1}, 2);

  // cout << endl
  //      << endl;
  // for (int d = 0; d < 3; d++)
  // {
  //   for (int i = 0; i < n; i++)
  //   {
  //     for (int j = 0; j < n; j++)
  //       cout << dp[d][i][j] << ' ';
  //     cout << endl;
  //   }
  //   cout << endl;
  // }

  return 0;
}
