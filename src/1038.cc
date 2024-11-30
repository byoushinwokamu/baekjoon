#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<ll, int> pp;

vector<ll> gs;
queue<pp> q;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n = 0;

  for (int i = 0; i < 10; i++) {
    gs.push_back(i);
    q.push({i, 1});
  }
  while (!q.empty()) {
    auto now = q.front();
    q.pop();
    if (now.se == 10)
      continue;
    ll last = now.fi % 10;
    now.fi *= 10;
    for (ll i = 0; i < last; i++) {
      gs.push_back(now.fi + i);
      q.push({now.fi + i, now.se + 1});
    }
  }

  cin >> n;
  cout << (n < gs.size() ? gs[n] : -1);

  return 0;
}
