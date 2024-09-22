#include <iostream>
#include <queue>

using namespace std;

int adj[101][101];
int visit[101];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    adj[a][b]++;
    adj[b][a]++;
  }

  int cnt = 0;
  queue<int> q;
  visit[1]++;
  q.push(1);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 1; i <= n; i++) {
      if (adj[now][i] && !visit[i]) {
        cnt++;
        visit[i]++;
        q.push(i);
      }
    }
  }
  cout << cnt;

  return 0;
}