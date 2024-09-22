#include <iostream>
#include <queue>

using namespace std;

// 탐색한 부분은 \0으로 저장, imga는 G도 R로 저장
char img[101][101];
char imga[101][101];
int n, cnt, cnta;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  queue<pair<int, int>> q;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> img[i];
    for (int j = 0; j < n; j++)
      imga[i][j] = (img[i][j] == 'B' ? 'B' : 'R');
  }

  // RGB
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (img[i][j] == 0)
        continue;
      char col = img[i][j];
      q.push(make_pair(i, j));
      img[i][j] = 0;
      cnt++;
      while (!q.empty()) {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
          int newx = nowx + (i % 2 + i / 2 - 1);
          int newy = nowy + (i % 2 - i / 2);
          if (nowx < 0 || nowy < 0 || nowx >= n || nowy >= n)
            continue;
          if (img[newx][newy] == col) {
            img[newx][newy] = 0;
            q.push(make_pair(newx, newy));
          }
        }
      }
    }
  }

  // (RG)B
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (imga[i][j] == 0)
        continue;
      char col = imga[i][j];
      q.push(make_pair(i, j));
      imga[i][j] = 0;
      cnta++;
      while (!q.empty()) {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
          int newx = nowx + (i % 2 + i / 2 - 1);
          int newy = nowy + (i % 2 - i / 2);
          if (nowx < 0 || nowy < 0 || nowx >= n || nowy >= n)
            continue;
          if (imga[newx][newy] == col) {
            imga[newx][newy] = 0;
            q.push(make_pair(newx, newy));
          }
        }
      }
    }
  }
  cout << cnt << " " << cnta;

  return 0;
}