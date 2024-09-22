#include <iostream>
#include <queue>

using namespace std;

int vis[200010];
int n, k;
queue<int> q;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  if (n == 0) {
    q.push(0);
    vis[0] = 1;
  } else
    for (int i = n; i <= 200000; i *= 2) {
      q.push(i);
      vis[i] = 1;
    }

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if (now == k) {
      cout << vis[now] - 1;
      return 0;
    }
    if (now > 0 && vis[now - 1] == 0) {
      if (now == 1) {
        q.push(0);
        vis[0] = vis[1] + 1;
      } else
        for (int i = now - 1; i <= 200000; i *= 2) {
          if (vis[i] > vis[now] + 1)
            break;
          q.push(i);
          vis[i] = vis[now] + 1;
        }
    }
    if (now < 200000 && vis[now + 1] == 0) {
      for (int i = now + 1; i <= 200000; i *= 2) {
        if (vis[i] > vis[now] + 1)
          break;
        q.push(i);
        vis[i] = vis[now] + 1;
      }
    }
  }

  return 0;
}