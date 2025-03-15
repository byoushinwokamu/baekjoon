// BOJ 2447

#include <iostream>
#include <string>

using namespace std;

int n, t;
char **str;

void del(int x, int y, int s) {
  if (s == 3) {
    str[x + 1][y + 1] = ' ';
    return;
  }
  int ss = s / 3;
  int xx = x + ss, xxx = xx + ss;
  int yy = y + ss, yyy = yy + ss;
  del(x, y, ss);
  del(xx, y, ss);
  del(xxx, y, ss);
  del(x, yy, ss);
  for (int i = xx; i < xxx; i++)
    for (int j = yy; j < yyy; j++)
      str[i][j] = ' ';
  del(xxx, yy, ss);
  del(x, yyy, ss);
  del(xx, yyy, ss);
  del(xxx, yyy, ss);
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n;
  str = new char *[n];
  for (int i = 0; i < n; i++) {
    str[i] = new char[n + 1];
    for (int j = 0; j < n; j++)
      str[i][j] = '*';
    str[i][n] = 0;
  }

  del(0, 0, n);
  for (int i = 0; i < n; i++)
    cout << str[i] << '\n';

  return 0;
}
