// BOJ 12100
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

void left(vector<vector<int>> &v)
{
  for (int r = 0; r < n; r++)
  {
    for (int c = 0; c < n - 1; c++)
    {
      if (!v[r][c]) // pull
      {
        for (int cc = c + 1; cc < n; cc++)
          if (v[r][cc])
          {
            for (int ccc = cc + 1; ccc < n; ccc++)
              if (v[r][cc] == v[r][ccc])
              {
                v[r][c] = v[r][cc] << 1, v[r][cc] = v[r][ccc] = 0;
                break;
              }
            break;
          }
      }
      else // merge
      {
        for (int cc = c + 1; cc < n; cc++)
          if (v[r][c] == v[r][cc])
          {
            v[r][c] <<= 1, v[r][cc] = 0;
            break;
          }
      }
    }
  }
}

void right(vector<vector<int>> &v)
{
  for (int r = 0; r < n; r++)
  {
    for (int c = n - 1; c > 0; c--)
    {
      if (!v[r][c]) // pull
      {
        for (int cc = c - 1; cc >= 0; cc--)
          if (v[r][cc])
          {
            for (int ccc = cc - 1; ccc >= 0; ccc--)
              if (v[r][cc] == v[r][ccc])
              {
                v[r][c] = v[r][cc] << 1, v[r][cc] = v[r][ccc] = 0;
                break;
              }
            break;
          }
      }
      else // merge
      {
        for (int cc = c - 1; cc >= 0; cc--)
          if (v[r][c] == v[r][cc])
          {
            v[r][c] <<= 1, v[r][cc] = 0;
            break;
          }
      }
    }
  }
}

void up(vector<vector<int>> &v)
{
  for (int c = 0; c < n; c++)
  {
    for (int r = 0; r < n - 1; r++)
    {
      if (!v[r][c]) // pull
      {
        for (int rr = r + 1; rr < n; rr++)
          if (v[rr][c])
          {
            for (int rrr = rr + 1; rrr < n; rrr++)
              if (v[rr][c] == v[rrr][c])
              {
                v[r][c] = v[rr][c] << 1, v[rr][c] = v[rrr][c] = 0;
                break;
              }
            break;
          }
      }
      else // merge
      {
        for (int rr = r + 1; rr < n; rr++)
          if (v[r][c] == v[rr][c])
          {
            v[r][c] <<= 1, v[rr][c] = 0;
            break;
          }
      }
    }
  }
}

void down(vector<vector<int>> &v)
{
  for (int c = 0; c < n; c++)
  {
    for (int r = n - 1; r > 0; r--)
    {
      if (!v[r][c]) // pull
      {
        for (int rr = r - 1; rr >= 0; rr--)
          if (v[rr][c])
          {
            for (int rrr = rr - 1; rrr >= 0; rrr--)
              if (v[rr][c] == v[rrr][c])
              {
                v[r][c] = v[rr][c] << 1, v[rr][c] = v[rrr][c] = 0;
                break;
              }
            break;
          }
      }
      else // merge
      {
        for (int rr = r - 1; rr >= 0; rr--)
          if (v[r][c] == v[rr][c])
          {
            v[r][c] <<= 1, v[rr][c] = 0;
            break;
          }
      }
    }
  }
}

void (*mover[4])(vector<vector<int>> &) = {left, right, up, down};

int mblock = 0;
void dfs(vector<vector<int>> board, int depth)
{
  if (depth == 5)
  {
    for (auto r : board)
      for (auto c : r)
        mblock = max(mblock, c);
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    auto b = board;
    mover[i](b);
    dfs(b, depth + 1);
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
  dfs(v, 0);
  cout << mblock;

  return 0;
}
