// BOJ 3190
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

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  queue<pp> snake;               // pp: pos
  queue<pair<int, char>> change; // fi: time, se: direction
  int n, k;
  cin >> n >> k;
  vector<vector<int>> board(n, vector<int>(n)); // 0: empty, 1: snake, 2: apple
  board[0][0] = 1;
  snake.push({0, 0});
  for (int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x >> y;
    board[x - 1][y - 1] = 2;
  }
  int l;
  cin >> l;
  for (int i = 0; i < l; i++)
  {
    int x;
    char c;
    cin >> x >> c;
    change.push({x, c});
  }

  int t = 0;
  pp now = {0, 0};
  int dir = RIGHT;
  while (++t)
  {
    now = {now.fi + dr[dir], now.se + dc[dir]};
    if (now.fi < 0 || now.se < 0 || now.fi >= n || now.se >= n) // 벽에 부딪힘
    {
      cout << t;
      return 0;
    }
    switch (board[now.fi][now.se])
    {
    case 0: // 빈 공간에 전진
      board[snake.front().fi][snake.front().se] = 0;
      snake.pop();
      board[now.fi][now.se] = 1;
      snake.push(now);
      break;
    case 1: // 자기 몸에 부딪힘
      cout << t;
      return 0;
    case 2: // 사과를 먹음
      board[now.fi][now.se] = 1;
      snake.push(now);
      break;
    }
    if (change.front().fi == t) // 방향 전환
    {
      if (change.front().se == 'L')
        dir = (dir + 3) % 4;
      else
        dir = (dir + 1) % 4;
      change.pop();
    }
  }

  return 0;
}
