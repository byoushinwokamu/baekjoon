#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> point;

point operator+(point a, point b) {
  return make_pair(a.first + b.first, a.second + b.second);
}

int canvas[501][501];
point tonari[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int checked[501][501];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  int n = 0, m = 0, k = 0;
  int count = 0;
  queue<point> q;  // 탐색 시작점 후보
  queue<point> qq; // 현재 탐색중인 배추덩어리
  int u1, u2;

  // 입력
  cin >> t;
  for (int a = 0; a < t; a++) {
    count = 0;
    cin >> m >> n >> k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        canvas[i][j] = 0;
        checked[i][j] = 0;
      }

    for (int i = 0; i < k; i++) {
      cin >> u1 >> u2;
      canvas[u1][u2] = 1;
      q.push(make_pair(u1, u2));
    }

    // dequeue해서 너비 우선 탐색
    while (!q.empty()) {
      if (!checked[q.front().first][q.front().second]) {
        qq.push(q.front()); // 후보 중 새 그림의 좌표를 enqueue
        count++;
        q.pop();
      } else {
        q.pop();
        continue;
      }

      // enqueue한 새 그림 너비 우선 탐색해 크기 확인
      checked[qq.front().first][qq.front().second] = 1;
      while (!qq.empty()) {
        point p = qq.front();
        qq.pop();
        for (point d : tonari) {
          point next = p + d;
          if (next.first == -1 || next.second == -1 || next.first == m ||
              next.second == n)
            continue;
          if (canvas[next.first][next.second] &&
              !checked[next.first][next.second]) {
            qq.push(next);
            checked[next.first][next.second] = 1;
          }
        }
      }
    }
    cout << count << '\n';
  }
  return 0;
}