// BOJ 12100
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

int n;
queue<int> q;
vector<vector<vector<int>>> board(6);

void left(vector<vector<int>> &v)
{
  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < n; c++)
      if (v[r][c]) q.push(v[r][c]);
    int cc = 0;
    while (!q.empty())
    {
      int now = q.front();
      q.pop();
      if (!q.empty() && q.front() == now) now <<= 1, q.pop();
      v[r][cc++] = now;
    }
    for (cc; cc < n; cc++) v[r][cc] = 0;
  }
}

void right(vector<vector<int>> &v)
{
  for (int r = 0; r < n; r++)
  {
    for (int c = n - 1; c >= 0; c--)
      if (v[r][c]) q.push(v[r][c]);
    int cc = n - 1;
    while (!q.empty())
    {
      int now = q.front();
      q.pop();
      if (!q.empty() && q.front() == now) now <<= 1, q.pop();
      v[r][cc--] = now;
    }
    for (cc; cc >= 0; cc--) v[r][cc] = 0;
  }
}

void up(vector<vector<int>> &v)
{
  for (int c = 0; c < n; c++)
  {
    for (int r = 0; r < n; r++)
      if (v[r][c]) q.push(v[r][c]);
    int rr = 0;
    while (!q.empty())
    {
      int now = q.front();
      q.pop();
      if (!q.empty() && q.front() == now) now <<= 1, q.pop();
      v[rr++][c] = now;
    }
    for (rr; rr < n; rr++) v[rr][c] = 0;
  }
}

void down(vector<vector<int>> &v)
{
  for (int c = 0; c < n; c++)
  {
    for (int r = n - 1; r >= 0; r--)
      if (v[r][c]) q.push(v[r][c]);
    int rr = n - 1;
    while (!q.empty())
    {
      int now = q.front();
      q.pop();
      if (!q.empty() && q.front() == now) now <<= 1, q.pop();
      v[rr--][c] = now;
    }
    for (rr; rr >= 0; rr--) v[rr][c] = 0;
  }
}

void (*mover[4])(vector<vector<int>> &) = {left, right, up, down};

int mblock = 0;
void dfs(int depth)
{
  if (depth == 5)
  {
    for (auto r : board[5])
    {
      for (auto c : r)
        mblock = max(mblock, c);
    }
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    board[depth + 1] = board[depth];
    mover[i](board[depth + 1]);
    dfs(depth + 1);
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> v[i][j];
  }

  board[0] = v;
  dfs(0);

  cout << mblock;

  return 0;
}
