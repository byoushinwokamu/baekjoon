#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> point;
point tonari[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int maze[100][100];
int visit[100][100];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  char input[101];
  queue<pair<point, int>> q; // 좌표와 원점으로부터의 거리를 모두 저장

  // 문자열 형태로 입력받은 미로를 int 2차원 배열로 변환
  for (int i = 0; i < n; i++) {
    cin >> input;
    for (int j = 0; j < m; j++)
      maze[j][i] = input[j] - 48;
  }

  // bfs
  q.push(make_pair(make_pair(0, 0), 1));
  visit[0][0] = 1;
  while (!q.empty()) {
    point now = q.front().first;
    int dis = q.front().second;
    if (now.first == m - 1 && now.second == n - 1) {
      cout << dis;
      return 0;
    }
    q.pop();
    for (point p : tonari) {
      point newp = make_pair(p.first + now.first, p.second + now.second);
      if (newp.first < 0 || newp.second < 0 || newp.first >= m ||
          newp.second >= n)
        continue;
      if (!visit[newp.first][newp.second] && maze[newp.first][newp.second]) {
        q.push(make_pair(newp, dis + 1));
        visit[newp.first][newp.second] = 1;
      }
    }
  }
  return 0;
}