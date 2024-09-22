#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

char dis[10000][10000];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int cas = 0; cas < t; cas++) {
    for (int i = 0; i < 10000; i++)
      dis[i][0] = 0;
    queue<int> q;
    int a, b;
    cin >> a >> b;
    q.push(a);
    while (q.front() != b) {
      int now = q.front();
      q.pop();

      int d = now * 2 % 10000;
      if (now != d && !dis[d][0]) {
        strcpy(dis[d], dis[now]);
        strcat(dis[d], "D");
        q.push(d);
      }

      int s = (now + 9999) % 10000;
      if (!dis[s][0]) {
        strcpy(dis[s], dis[now]);
        strcat(dis[s], "S");
        q.push(s);
      }

      int l = (now * 10 % 10000) + (now / 1000);
      if (now != l && !dis[l][0]) {
        strcpy(dis[l], dis[now]);
        strcat(dis[l], "L");
        q.push(l);
      }

      int r = (now / 10) + (now % 10 * 1000);
      if (now != r && !dis[r][0]) {
        strcpy(dis[r], dis[now]);
        strcat(dis[r], "R");
        q.push(r);
      }
    }
    cout << dis[q.front()] << '\n';
  }

  return 0;
}