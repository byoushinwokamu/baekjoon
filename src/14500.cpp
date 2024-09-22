#include <iostream>

using namespace std;

int paper[500][500];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> paper[i][j];

  int max = 0;
  int temp;
  // 파란거 세로로
  for (int i = 0; i < n - 3; i++) {
    for (int j = 0; j < m; j++) {
      temp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j];
      max = max > temp ? max : temp;
    }
  }
  // 파란거 가로로
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 3; j++) {
      temp = paper[i][j] + paper[i][j + i] + paper[i][j + 2] + paper[i][j + 3];
      max = max > temp ? max : temp;
    }
  }
  // 노란거
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      temp =
          paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1];
      max = max > temp ? max : temp;
    }
  }
  // 주황색 가로로
  // 2*3에서 허용되는 빈칸 15개중 10가지
  // 12 23 34 45 56 61 13 46 14/36(노랑)
  // 허용 안되는 빈칸 5가지
  // 15 25 35 24 26
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 2; j++) {
      // 12
      temp = paper[i][j + 2] + paper[i + 1][j] + paper[i + 1][j + 1] +
             paper[i + 1][j + 2];
      max = max > temp ? max : temp;
      // 23
      temp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] +
             paper[i + 1][j + 2];
      max = max > temp ? max : temp;
      // 34
      temp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] +
             paper[i + 1][j + 2];
      max = max > temp ? max : temp;
      // 45
      temp =
          paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2];
      max = max > temp ? max : temp;
      // 56
      temp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j];
      max = max > temp ? max : temp;
      // 61
      temp = paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j] +
             paper[i + 1][j + 1];
      max = max > temp ? max : temp;
      // 13
      temp = paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1] +
             paper[i + 1][j + 2];
      max = max > temp ? max : temp;
      // 46
      temp =
          paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1];
      max = max > temp ? max : temp;
    }
  }
  // 주황색 세로로
  // 3*2에서 허용되는 빈칸 15개중 10가지
  // 13 15 16 24 25 26 35 46 12/56(노랑)
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 1; j++) {
      // 13 - 2456
      temp = paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j] +
             paper[i + 2][j + 1];
      max = max > temp ? max : temp;
      // 15 - 2346
      temp = paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1] +
             paper[i + 2][j + 1];
      max = max > temp ? max : temp;
      // 16 - 2345
      temp = paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1] +
             paper[i + 2][j];
      max = max > temp ? max : temp;
      // 24 - 1356
      temp =
          paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1];
      max = max > temp ? max : temp;
      // 25 - 1346
      temp = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] +
             paper[i + 2][j + 1];
      max = max > temp ? max : temp;
      // 26 - 1345
      temp =
          paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j];
      max = max > temp ? max : temp;
      // 35 - 1246
      temp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] +
             paper[i + 2][j + 1];
      max = max > temp ? max : temp;
      // 46 - 1235
      temp = paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 2][j];
      max = max > temp ? max : temp;
    }
  }
  cout << max;

  return 0;
}