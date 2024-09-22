#include <iostream>

using namespace std;

int paper[128][128];
int count[2];

void cutpaper(int x, int y, int len) {
  if (len == 1) {
    count[paper[x][y]]++;
    return;
  }
  int now = paper[x][y];
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (paper[i + x][j + y] != now) {
        cutpaper(x, y, len / 2);
        cutpaper(x, y + len / 2, len / 2);
        cutpaper(x + len / 2, y, len / 2);
        cutpaper(x + len / 2, y + len / 2, len / 2);
        return;
      }
    }
  }
  count[now]++;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> paper[i][j];

  cutpaper(0, 0, n);
  cout << count[0] << '\n' << count[1];
  return 0;
}