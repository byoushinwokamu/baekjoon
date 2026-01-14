// BOJ 18809-2
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

typedef enum
{
  f_lake,
  f_white,
  f_yellow,
} cell_fi;

typedef enum
{
  s_empty,
  s_green,
  s_red,
  s_flower
} cell_se;

typedef pair<cell_fi, cell_se> ppc;

int n, m, g, r, maxflower = 0;
vector<pp> v_yellow;
vector<pp> v_green;
vector<pp> v_red;

int doit(vector<vector<ppc>> board)
{
  int flower = 0;
  int tim = 0;

  queue<pair<pp, int>> q;
  for (auto p : v_green) q.push({p, 0});
  for (auto p : v_red) q.push({p, 0});
  vector<vector<ppc>> board_after = board;

  while (!q.empty())
  {
    while (!q.empty() && q.front().se == tim)
    {
      ;
    }
    tim++;
  }

  return 0;
}

void dfs(pp depth, int bef, vector<vector<ppc>> &board) // depth {green, red}
{
  if (depth == make_pair(g, r)) maxflower = max(maxflower, doit(board));
  else
  {
    for (int i = bef + 1; i < v_yellow.size(); i++)
    {
      if (depth.fi < g)
      {
        board[v_yellow[i].fi][v_yellow[i].se].se = s_green;
        v_green[depth.fi] = v_yellow[i];
        dfs({depth.fi + 1, depth.se}, i, board);
        board[v_yellow[i].fi][v_yellow[i].se].se = s_empty;
      }
      if (depth.se < r)
      {
        board[v_yellow[i].fi][v_yellow[i].se].se = s_red;
        v_red[depth.se] = v_yellow[i];
        dfs({depth.fi, depth.se + 1}, i, board);
        board[v_yellow[i].fi][v_yellow[i].se].se = s_empty;
      }
    }
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int a;
  cin >> n >> m >> g >> r;
  vector<vector<ppc>> board(n, vector<ppc>(m));
  v_green.resize(g);
  v_red.resize(r);
  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < m; c++)
    {
      cin >> a;
      if (a == 0) board[r][c] = {f_lake, s_empty};
      else if (a == 1) board[r][c] = {f_white, s_empty};
      else if (a == 2) board[r][c] = {f_yellow, s_empty}, v_yellow.push_back({r, c});
    }
  }
  dfs({0, 0}, -1, board);
  cout << maxflower;

  return 0;
}
