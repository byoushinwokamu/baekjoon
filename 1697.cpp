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
  if (n == k) {
    cout << 0;
    return 0;
  }
  dis[n] = 0;

  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    int nex[3] = {now + 1, now - 1, 2 * now};
    for (int i = 0; i < 3; i++) {
      if (nex[i] < 0 || nex[i] > 100000)
        continue;
      if (nex[i] == k) {
        cout << dis[now] + 1;
        return 0;
      }
      if (dis[nex[i]] == 0) {
        dis[nex[i]] = dis[now] + 1;
        q.push(nex[i]);
      }
    }
  }

  return 0;
}