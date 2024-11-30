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

int t, n, x, y;
pp home, ptpt;
vector<pp> conv;
vector<bool> reachable;
bool cango;

int dist(const pp &p1, const pp &p2) {
  return abs(p1.fi - p2.fi) + abs(p1.se - p2.se);
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    // initialize and input
    cango = false;
    cin >> n >> x >> y;
    home = {x, y};
    conv.clear();
    conv.resize(n);
    reachable.clear();
    reachable.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      conv[i] = {x, y};
    }
    cin >> x >> y;
    ptpt = {x, y};

    // solve
    queue<pp> q;
    q.push(home);
    while (!q.empty()) {
      pp now = q.front();
      q.pop();
      if (dist(now, ptpt) <= 1000) {
        cango = true;
        break;
      }
      for (int i = 0; i < n; i++) {
        if (!reachable[i] && (dist(now, conv[i]) <= 1000)) {
          reachable[i] = true;
          q.push(conv[i]);
        }
      }
    }

    // result
    cout << (cango ? "happy\n" : "sad\n");
  }

  return 0;
}
