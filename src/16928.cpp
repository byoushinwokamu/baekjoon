#include <iostream>
#include <queue>

using namespace std;

int dis[101];
int jump[101];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m, x, y;
  cin >> n >> m;
  n += m;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    jump[x] = y;
  }

  dis[1] = 1;
  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int now = q.front();
    int disnow = dis[now];
    int nex;
    q.pop();
    for (int i = 1; i <= 6; i++) {
      nex = now + i;
      if (nex > 100)
        continue;
      if (nex == 100) {
        cout << disnow;
        return 0;
      } else if (jump[nex] && !dis[jump[nex]]) {
        dis[jump[nex]] = disnow + 1;
        q.push(jump[nex]);
      } else if (!jump[nex] && !dis[nex]) {
        dis[nex] = disnow + 1;
        q.push(nex);
      }
    }
  }

  return 0;
}