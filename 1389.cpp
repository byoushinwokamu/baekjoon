#include <iostream>
#include <queue>

using namespace std;

int adj[100][100];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1][b - 1]++;
    adj[b - 1][a - 1]++;
  }

  int minman = -1;
  int minbac = -1;
  queue<pair<int, int>> q;
  for (int start = 0; start < n; start++) {
    int bacon = 0;
    int visited[100] = {
        0,
    };
    q.push(make_pair(start, 0));
    while (!q.empty()) {
      int now = q.front().first;
      int nowbac = q.front().second;
      bacon += nowbac;
      q.pop();
      for (int i = 0; i < n; i++) {
        if (!visited[i] && adj[now][i]) {
          visited[i]++;
          q.push(make_pair(i, nowbac + 1));
        }
      }
    }
    if (minbac < 0 || minbac > bacon) {
      minbac = bacon;
      minman = start;
    }
  }
  cout << minman + 1;

  return 0;
}