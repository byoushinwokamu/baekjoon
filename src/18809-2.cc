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
  s_closed // Flower / Lake
} cell_se;

typedef struct
{
  cell_se stat;
  int wateredTime;
} cell_t; // 로 바꾸기

typedef pair<cell_fi, cell_se> ppc;

int n, m, g, r, maxflower = 0;
vector<pp> v_yellow;
vector<pp> v_green;
vector<pp> v_red;

constexpr pp dp[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pp operator+(const pp &a, const pp &b) { return {a.fi + b.fi, a.se + b.se}; }
bool valid(const pp &p) { return p.fi >= 0 && p.se >= 0 && p.fi < n && p.se < m; }
int conv(const pp &p) { return p.fi * m + p.se; }

int doit(vector<cell_t> board)
{
  int flower = 0;
  int tim = 0;

  queue<pair<pp, int>> q;
  for (auto p : v_green) q.push({p, 0});
  for (auto p : v_red) q.push({p, 0});

  while (!q.empty())
  {
    while (!q.empty() && q.front().se == tim)
    {
      pp nowp = q.front().fi;
      int cp = conv(nowp);
      q.pop();
      if (board[cp].stat == s_closed) continue; // 큐에 넣어놨는데 꽃핌
      for (auto d : dp)
      {
        pp nextp = nowp + d;
        if (!valid(nextp)) continue; // 바깥
        int cnp = conv(nextp);
        if (board[cnp].stat == s_closed) continue; // 호수 / 꽃

        if (board[cnp].stat == s_red)
        {
          if (board[cnp].wateredTime == tim + 1 && board[cp].stat == s_green) // 꽃핌
            board[cnp].stat = s_closed, flower++;
        }
        else if (board[cnp].stat == s_green)
        {
          if (board[cnp].wateredTime == tim + 1 && board[cp].stat == s_red) // 꽃핌
            board[cnp].stat = s_closed, flower++;
        }
        else // empty
        {
          board[cnp].stat = board[cp].stat;
          board[cnp].wateredTime = tim + 1;
          q.push({nextp, tim + 1});
        }
      }
    }
    tim++;
  }
  // cout << "f " << flower << endl;
  // for (auto vp : board_after)
  // {
  //   for (auto p : vp)
  //     cout << p.se << ' ';
  //   cout << '\n';
  // }
  // cout << endl;
  return flower;
}

void dfs(pp depth, int bef, vector<cell_t> &board) // depth {green, red}
{
  if (depth == make_pair(g, r)) maxflower = max(maxflower, doit(board));
  else
  {
    for (int i = bef + 1; i < v_yellow.size(); i++)
    {
      if (depth.fi < g)
      {
        board[conv(v_yellow[i])].stat = s_green;
        v_green[depth.fi] = v_yellow[i];
        dfs({depth.fi + 1, depth.se}, i, board);
        board[conv(v_yellow[i])].stat = s_empty;
      }
      if (depth.se < r)
      {
        board[conv(v_yellow[i])].stat = s_red;
        v_red[depth.se] = v_yellow[i];
        dfs({depth.fi, depth.se + 1}, i, board);
        board[conv(v_yellow[i])].stat = s_empty;
      }
    }
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int a;
  cin >> n >> m >> g >> r;
  vector<cell_t> board(n * m);
  v_green.resize(g);
  v_red.resize(r);
  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < m; c++)
    {
      int p = conv({r, c});
      cin >> a;
      if (a == 0) board[p] = {s_closed, 0};
      else if (a == 1) board[p] = {s_empty, 0};
      else if (a == 2) board[p] = {s_empty, 0}, v_yellow.push_back({r, c});
    }
  }
  dfs({0, 0}, -1, board);
  cout << maxflower;

  return 0;
}
