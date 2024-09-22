#include <iostream>
#include <queue>

using namespace std;

int dis[100001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  dis[n] = 1;
  queue<int> q;
  q.push(n);

  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if (now == k) {
      cout << dis[now] - 1;
      return 0;
    }
    for (int i = -1; i < 2; i += 2) {
      if (now + i > 100000 || now + i < 0)
        continue;
      if (dis[now + i])
        continue;
      dis[now + i] = dis[now] + 1;
      q.push(now + i);
    }
    if (now * 2 > 100000 || now == 0)
      continue;
    if (dis[now * 2])
      continue;
    dis[now * 2] = dis[now] + 1;
    q.push(now * 2);
  }

  return 0;
}