#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int a, b, n, m, x, y;
vector<int> v[101];
int chon[101];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n >> a >> b >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  chon[a] = 1;
  chon[b] = 0;
  queue<int> q;
  q.push(a);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i : v[now]) {
      if (!chon[i]) {
        chon[i] = chon[now] + 1;
        q.push(i);
      }
    }
  }
  cout << chon[b] - 1;

  return 0;
}