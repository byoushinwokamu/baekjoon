// BOJ 9466
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

vector<int> sel;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    sel.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> sel[i];
      sel[i]--;
    }
    vector<bool> team(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
      if (team[i])
        continue;
      if (vis[i])
        continue;
      vis[i] = true;

      int cur;
      for (cur = sel[i]; !vis[cur]; cur = sel[cur])
        vis[cur] = true;
      team[cur] = true;
      for (int cc = sel[cur]; cc != cur; cc = sel[cc])
        team[cc] = true;
    }

    // count # of assa
    int cnt = n;
    for (auto tt : team)
      if (tt)
        cnt--;
    cout << cnt << '\n';
  }

  return 0;
}
