// BOJ 1799
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n;
vector<vector<bool>> board(10, vector<bool>(10)); // true면 놓을 수 있음
vector<bool> slash(18);                           // /형태 대각선 맨윗점 좌표기준, true면 이미 먹힌 줄
vector<bool> backslash(18);                       // \형태 대각선 맨윗점 좌표기준, 오프셋 9
int maxbishop;

int getslash(const pp &p) { return p.se + p.fi; }
int getbackslash(const pp &p) { return p.se - p.fi + 9; }

void dfs(vector<pp> &place, int ps, int depth, int bef)
{
  maxbishop = max(depth, maxbishop);
  for (int pn = bef + 1; pn < ps; pn++)
  {
    pp now = place[pn];
    if (!board[now.fi][now.se]) continue;
    int s = getslash(now), bs = getbackslash(now);
    if (slash[s] || backslash[bs]) continue;

    slash[s] = true, backslash[bs] = true;
    dfs(place, ps, depth + 1, pn);
    slash[s] = false, backslash[bs] = false;
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int a;
  cin >> n;
  vector<pp> placew, placeb; // 놓을 수 있는 좌표
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a;
      board[i][j] = a == 1;
      if (board[i][j])
        if ((i + j) % 2)
          placew.push_back({i, j});
        else
          placeb.push_back({i, j});
    }
  dfs(placew, placew.size(), 0, -1);
  int mb = maxbishop;
  maxbishop = 0;
  dfs(placeb, placeb.size(), 0, -1);
  cout << maxbishop + mb;

  return 0;
}
