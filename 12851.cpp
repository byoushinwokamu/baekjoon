#include <iostream>
#include <queue>

using namespace std;

int vis[100001]; // ways
int ttt[100001]; // time

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  queue<pair<int, int>> q;
  q.push(make_pair(n, 0));
  vis[n] = 1;
  int t = -1;

  while (!q.empty()) {
    int now = q.front().first;
    int tim = q.front().second;
    q.pop();

    if (now == k) {
      t = tim;
      break;
    }

    if (now > 0) {
      if (!vis[now - 1]) {
        q.push(make_pair(now - 1, tim + 1));
        ttt[now - 1] = tim;
      }
      if (ttt[now - 1] == tim)
        vis[now - 1] += vis[now];
    }
    if (now < 100000) {
      if (!vis[now + 1]) {
        q.push(make_pair(now + 1, tim + 1));
        ttt[now + 1] = tim;
      }
      if (ttt[now + 1] == tim)
        vis[now + 1] += vis[now];
    }
    if (now <= 50000) {
      if (!vis[now * 2]) {
        q.push(make_pair(now * 2, tim + 1));
        ttt[now * 2] = tim;
      }
      if (ttt[now * 2] == tim)
        vis[now * 2] += vis[now];
    }
  }
  cout << t << '\n' << vis[k];

  return 0;
}