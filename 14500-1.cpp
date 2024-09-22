#include <iostream>

using namespace std;

int paper[505][505];
int n, m;

int orangemax(int x, int y) { // also magenta
  int max = 0;
  int temp, temp2;
  // 세로2 가로3
  if (x < n - 1 && y < m - 2) {
    temp = paper[x][y] + paper[x][y + 1] + paper[x][y + 2];
    temp2 = paper[x + 1][y];
    temp2 = temp2 > paper[x + 1][y + 1] ? temp2 : paper[x + 1][y + 1];
    temp2 = temp2 > paper[x + 1][y + 2] ? temp2 : paper[x + 1][y + 2];
    temp += temp2;
    max = temp;

    temp = paper[x + 1][y] + paper[x + 1][y + 1] + paper[x + 1][y + 2];
    temp2 = paper[x][y];
    temp2 = temp2 > paper[x][y + 1] ? temp2 : paper[x][y + 1];
    temp2 = temp2 > paper[x][y + 2] ? temp2 : paper[x][y + 2];
    temp += temp2;
    max = max > temp ? max : temp;
  }
  // 세로3 가로2
  if (x < n - 2 && y < m - 1) {
    temp = paper[x][y] + paper[x + 1][y] + paper[x + 2][y];
    temp2 = paper[x][y + 1];
    temp2 = temp2 > paper[x + 1][y + 1] ? temp2 : paper[x + 1][y + 1];
    temp2 = temp2 > paper[x + 2][y + 1] ? temp2 : paper[x + 2][y + 1];
    temp += temp2;
    max = max > temp ? max : temp;

    temp = paper[x][y + 1] + paper[x + 1][y + 1] + paper[x + 2][y + 1];
    temp2 = paper[x][y];
    temp2 = temp2 > paper[x + 1][y] ? temp2 : paper[x + 1][y];
    temp2 = temp2 > paper[x + 2][y] ? temp2 : paper[x + 2][y];
    temp += temp2;
    max = max > temp ? max : temp;
  }
  return max;
}

int yellowmax(int x, int y) {
  if (x > n - 2 || y > m - 2)
    return 0;
  return paper[x][y] + paper[x][y + 1] + paper[x + 1][y] + paper[x + 1][y + 1];
}

int greenmax(int x, int y) {
  int max = 0;
  int temp;
  // 세로2 가로3
  if (x < n - 1 && y < m - 2) {
    temp = paper[x][y] + paper[x][y + 1] + paper[x + 1][y + 1] +
           paper[x + 1][y + 2];
    max = temp;

    temp = paper[x][y + 1] + paper[x][y + 2] + paper[x + 1][y] +
           paper[x + 1][y + 1];
    max = max > temp ? max : temp;
  }
  // 세로3 가로2
  if (x < n - 2 && y < m - 1) {
    temp = paper[x][y] + paper[x + 1][y] + paper[x + 1][y + 1] +
           paper[x + 2][y + 1];
    max = max > temp ? max : temp;

    temp = paper[x][y + 1] + paper[x + 1][y + 1] + paper[x + 1][y] +
           paper[x + 2][y];
    max = max > temp ? max : temp;
  }
  return max;
}

int cyanmax(int x, int y) {
  int max = 0;
  int temp;
  if (x < n - 3) { // 세로
    temp = paper[x][y] + paper[x + 1][y] + paper[x + 2][y] + paper[x + 3][y];
    max = temp;
  }
  if (y < m - 3) { // 가로
    temp = paper[x][y] + paper[x][y + 1] + paper[x][y + 2] + paper[x][y + 3];
    max = max > temp ? max : temp;
  }
  return max;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> paper[i][j];

  int max = 0;
  int temp;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      temp = orangemax(i, j);
      max = max > temp ? max : temp;
      temp = yellowmax(i, j);
      max = max > temp ? max : temp;
      temp = greenmax(i, j);
      max = max > temp ? max : temp;
      temp = cyanmax(i, j);
      max = max > temp ? max : temp;
    }
  }

  cout << max;

  return 0;
}