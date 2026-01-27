// BOJ 16946
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n, m, nm;
pp operator+(const pp &a, const pp &b) { return {a.fi + b.fi, a.se + b.se}; }
int conv(const pp &p) { return p.fi * m + p.se; }
bool valid(const pp &p) { return p.fi >= 0 && p.se >= 0 && p.fi < n && p.se < m; }
constexpr pp dp[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> m;
  nm = n * m;
  vector<string> board(n);
  vector<int> movegroup(nm); // movable group index: 1부터 시작(0은 no visit)
  vector<int> movable(1);    // 해당 그룹의 이동 가능한 칸수(속한 칸수)
  vector<pp> walls;
  for (int i = 0; i < n; i++)
  {
    cin >> board[i];
    for (int j = 0; j < m; j++)
      if (board[i][j] == '1') walls.push_back({i, j});
  }

  int mv = 1;
  movable.push_back(0);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == '0' && movegroup[conv({i, j})] == 0)
      {
        queue<pp> q;
        movegroup[conv({i, j})] = mv;
        q.push({i, j});
        movable[mv]++;

        while (!q.empty())
        {
          pp now = q.front();
          q.pop();
          for (auto d : dp)
          {
            pp next = now + d;
            if (!valid(next)) continue;                   // 맵 밖
            if (board[next.fi][next.se] == '1') continue; // 벽
            if (movegroup[conv(next)] > 0) continue;      // 이미 방문
            movegroup[conv(next)] = mv;
            movable[mv]++;
            q.push(next);
          }
        }
      }
      movable.push_back(0);
      mv++;
    }
  }

  for (auto w : walls)
  {
    int c = 1;
    set<int> mvg;
    for (auto d : dp)
    {
      pp next = w + d;
      if (!valid(next)) continue;                   // 벽 밖
      if (board[next.fi][next.se] == '1') continue; // 벽
      mvg.insert(movegroup[conv(next)]);
    }
    for (auto i : mvg)
      c += movable[i];
    board[w.fi][w.se] = c % 10 + '0';
  }

  for (auto s : board) cout << s << '\n';

  return 0;
}
