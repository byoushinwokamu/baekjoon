#include <iostream>
#include <queue>

using namespace std;

int height[100][100];
int checked[100][100];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> height[i][j];

  int maxregion = 0;
  queue<pair<int, int>> q;

  for (int rain = 0; rain <= 100; rain++) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        checked[i][j] = 0;
    int region = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (height[i][j] <= rain || checked[i][j])
          continue;
        region++;
        checked[i][j] = 1;
        q.push(make_pair(i, j));

        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int xx = x + (k % 2 - k / 2);
            int yy = y + (k % 2 + k / 2 - 1);
            if (xx < 0 || yy < 0 || xx >= n || yy >= n)
              continue;
            if (!checked[xx][yy] && height[xx][yy] > rain) {
              checked[xx][yy] = 1;
              q.push(make_pair(xx, yy));
            }
          }
        }
      }
    }
    maxregion = maxregion > region ? maxregion : region;
  }
  cout << maxregion;

  return 0;
}