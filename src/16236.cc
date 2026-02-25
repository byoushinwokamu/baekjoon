// BOJ 16236
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;
typedef pair<pp, int> ppp;
#define x    fi.fi
#define y    fi.se
#define time se

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int n, t, eatt;
int agi_size = 2;
int agi_ate = 0;
vector<int> eatable(7);
int eatable_n;
pp agi_pos;
vector<vector<int>> board;

constexpr pp dp[] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  cin >> n;
  board.resize(n);
  for (int i = 0; i < n; i++)
  {
    board[i].resize(n);
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 9) agi_pos = {i, j}, board[i][j] = 0;
      else eatable[board[i][j]]++;
    }
  }

  while (true)
  {
    eatable_n = 0;
    for (int i = 1; i < agi_size; i++)
      eatable_n += eatable[i];
    if (eatable_n == 0) break;

    vector<pp> toeat;
    vector<vector<bool>> vis(n, vector<bool>(n));
    queue<ppp> q;

    q.push({agi_pos, t});
    vis[agi_pos.fi][agi_pos.se] = true;

    while (!q.empty())
    {
      ppp now = q.front();
      q.pop();
      if (now.time != t) // 이번 breadth 다 돌았음
      {
        // cout << "TIME " << t << endl;
        t++;
        if (!toeat.empty()) // 해당 breadth에 먹을게 있음
          break;
      }

      for (auto d : dp)
      {
        pp next = {now.x + d.fi, now.y + d.se};
        if (next.fi < 0 || next.se < 0 || next.fi >= n || next.se >= n) continue; // 밖
        if (vis[next.fi][next.se]) continue;                                      // 이미옴

        if (board[next.fi][next.se] > agi_size) continue;                      // 못지나감
        else q.push({next, t + 1}), vis[next.fi][next.se] = true;              // 지나갈만함
        if (board[next.fi][next.se] > 0 && board[next.fi][next.se] < agi_size) // 먹을만함
          toeat.push_back(next), vis[next.fi][next.se] = true;
      }
    }

    if (toeat.empty()) break;

    // 먹을 물고기 정하기
    sort(toeat.begin(), toeat.end(), [](const pp &a, const pp &b)
         { return a.fi != b.fi ? a.fi < b.fi : a.se < b.se; });

    // 사이즈 업데이트
    if (++agi_ate == agi_size) agi_size++, agi_ate = 0;

    // 물고기 개수 업데이트
    eatable[board[toeat[0].fi][toeat[0].se]]--;

    // 보드 업데이트
    board[toeat[0].fi][toeat[0].se] = 0;
    eatt = t;
    // cout << agi_pos << " / " << agi_size << endl;
    agi_pos = toeat[0];
  }

  // cout << agi_pos << " / " << agi_size << endl;
  cout << eatt;

  return 0;
}
