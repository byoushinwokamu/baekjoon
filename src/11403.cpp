#include <iostream>
#include <queue>

using namespace std;
int adj[100][100];
int res[100][100];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> adj[i][j];

  for (int i = 0; i < n; i++) {
    queue<int> q;
    for (int j = 0; j < n; j++) {
      if (adj[i][j]) {
        res[i][j] = 1;
        q.push(j);
      }
    }
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int j = 0; j < n; j++) {
        if (adj[now][j] && !res[i][j]) {
          res[i][j] = 1;
          q.push(j);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << res[i][j] << " ";
    cout << '\n';
  }

  return 0;
}