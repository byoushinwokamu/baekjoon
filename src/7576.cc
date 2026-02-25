// BOJ 7576
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second
#define x  fi
#define y  se

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }
pp operator+(const pp &a, const pp &b) { return {a.fi + b.fi, a.se + b.se}; }
constexpr pp dp[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n, toripe = 0, riped = 0;
bool validpos(const pp &p) { return p.fi >= 0 && p.se >= 0 && p.fi < n && p.se < m; }

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  cin >> m >> n;
  vector<vector<int>> v(n, vector<int>(m));
  queue<pp> tmt;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> v[i][j], v[i][j]--;
      if (v[i][j] == -1) toripe++;
      else if (v[i][j] == 0) tmt.push({i, j});
    }
  }
  if (toripe == 0)
  {
    cout << 0;
    return 0;
  }

  int maxday = 0;

  while (!tmt.empty())
  {
    pp now = tmt.front();
    tmt.pop();
    for (auto d : dp)
    {
      pp next = d + now;
      if (!validpos(next)) continue;
      if (v[next.x][next.y] == -1)
      {
        v[next.x][next.y] = v[now.x][now.y] + 1;
        tmt.push(next);
        riped++;
        maxday = max(maxday, v[next.x][next.y]);
      }
    }
  }
  if (riped == toripe) cout << maxday;
  else cout << -1;

  return 0;
}
