// BOJ 1045
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

istream &operator>>(istream &is, pp &p) { return is >> p.fi >> p.se; }
ostream &operator<<(ostream &os, const pp &p) { return os << p.fi << ' ' << p.se << ' '; }

int n, m;
int parent[50];

int found(int x)
{
  if (parent[x] == x) return x;
  return parent[x] = found(parent[x]);
}

void onion(int x, int y)
{
  int rx = found(x), ry = found(y);
  if (rx < ry) parent[ry] = rx;
  else if (rx > ry) parent[rx] = ry;
}

int main()
{
  cin.tie(nullptr), ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) parent[i] = i;
  string adj;
  vector<pp> ed;
  vector<int> road(n);
  for (int i = 0; i < n; i++)
  {
    cin >> adj;
    for (int j = i + 1; j < n; j++)
    {
      if (adj[j] == 'Y') ed.push_back({i, j});
    }
  }
  sort(ed.begin(), ed.end(), [](const pp &a, const pp &b)
       { return a.fi == b.fi ? a.se < b.se : a.fi < b.fi; });

  int te = 0;
  int i;
  vector<bool> added(ed.size());
  for (i = 0; i < ed.size(); i++)
  {
    if (te == n - 1) break;
    if (found(ed[i].fi) == found(ed[i].se)) continue;
    onion(ed[i].fi, ed[i].se);
    road[ed[i].fi]++, road[ed[i].se]++;
    te++;
    added[i] = true;
  }
  if (te < n - 1)
  {
    cout << -1;
    return 0;
  }

  for (i = 0; i < ed.size(); i++)
  {
    if (te == m) break;
    if (added[i]) continue;
    road[ed[i].fi]++, road[ed[i].se]++;
    te++;
    added[i] = true;
  }

  if (te == m)
    for (int i = 0; i < n; i++) cout << road[i] << ' ';
  else
    cout << -1;

  return 0;
}
