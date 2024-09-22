#include <iostream>
#include <queue>

using namespace std;

int floor[1000001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int f, s, g, u, d; // 총, 출발, 도착, 업, 다운
  cin >> f >> s >> g >> u >> d;
  if (s == g) {
    cout << 0;
    return 0;
  }
  floor[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int dis = floor[q.front()];
    int nextf[2] = {q.front() + u, q.front() - d};
    q.pop();
    for (int i = 0; i < 2; i++) {
      if (nextf[i] < 1 || nextf[i] > f)
        continue;
      if (nextf[i] == g) {
        cout << dis;
        return 0;
      }
      if (floor[nextf[i]] == 0) {
        floor[nextf[i]] = dis + 1;
        q.push(nextf[i]);
      }
    }
  }

  cout << "use the stairs";

  return 0;
}