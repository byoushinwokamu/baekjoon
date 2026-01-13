// BOJ 2239
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<string> sudoku(9);
vector<pp> blank;
int blank_cur = 0;
int blank_size;

vector<vector<bool>> sqflag(9, vector<bool>(10));
vector<vector<bool>> rowflag(9, vector<bool>(10));
vector<vector<bool>> colflag(9, vector<bool>(10));

void dfs(int depth)
{
  // cout << "\ndepth " << depth << endl;
  int r = blank[depth].fi;
  int c = blank[depth].se;
  int sq = r / 3 * 3 + c / 3;
  if (depth == blank_size)
  {
    for (int i = 0; i < 9; i++)
      cout << sudoku[i] << '\n';
    exit(0);
  }
  for (int i = 1; i <= 9; i++)
  {
    if (sqflag[sq][i] || rowflag[r][i] || colflag[c][i])
      continue;
    // cout << i;
    sudoku[blank[depth].fi][blank[depth].se] += i;
    sqflag[sq][i] = rowflag[r][i] = colflag[c][i] = true;
    dfs(depth + 1);
    sudoku[blank[depth].fi][blank[depth].se] -= i;
    sqflag[sq][i] = rowflag[r][i] = colflag[c][i] = false;
  }
}

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  for (int i = 0; i < 9; i++)
  {
    cin >> sudoku[i];
    for (int j = 0; j < 9; j++)
      if (sudoku[i][j] == '0') blank.push_back({i, j});
      else sqflag[i / 3 * 3 + j / 3][sudoku[i][j] - '0'] = rowflag[i][sudoku[i][j] - '0'] = colflag[j][sudoku[i][j] - '0'] = true;
  }

  blank_size = blank.size();
  dfs(0);

  return 0;
}
