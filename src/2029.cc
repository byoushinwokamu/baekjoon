#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  string s;
  int st = 0, sq = 0;
  vector<vector<int>> v(7, vector<int>(7));
  for (int i = 0; i < 10; i++) {
    cin >> s;
    if (i % 3 == 0) {
      v[i / 3 * 2][1] = (s[1] == '-' ? 1 : 0);
      v[i / 3 * 2][3] = (s[4] == '-' ? 1 : 0);
      v[i / 3 * 2][5] = (s[7] == '-' ? 1 : 0);
      st += (s[1] == '-' ? 1 : 0);
      st += (s[4] == '-' ? 1 : 0);
      st += (s[7] == '-' ? 1 : 0);
    } else if (i % 3 == 1) {
      v[i / 3 * 2 + 1][0] = (s[0] == '|' ? 1 : 0);
      v[i / 3 * 2 + 1][2] = (s[3] == '|' ? 1 : 0);
      v[i / 3 * 2 + 1][4] = (s[6] == '|' ? 1 : 0);
      v[i / 3 * 2 + 1][6] = (s[9] == '|' ? 1 : 0);
      st += (s[0] == '|' ? 1 : 0);
      st += (s[3] == '|' ? 1 : 0);
      st += (s[6] == '|' ? 1 : 0);
      st += (s[9] == '|' ? 1 : 0);
    }
  }
  // for (auto a : v) {
  //   for (auto b : a)
  //     cout << b << ' ';
  //   cout << endl;
  // }
  // 1x1 square
  for (int i = 1; i <= 5; i += 2) {
    for (int j = 1; j <= 5; j += 2) {
      if (v[i - 1][j] + v[i + 1][j] + v[i][j - 1] + v[i][j + 1] == 4)
        sq++;
    }
  }

  // 2x2 square
  for (int i = 1; i <= 3; i += 2) {
    for (int j = 1; j <= 3; j += 2) {
      if (v[i - 1][j] + v[i + 3][j] + v[i - 1][j + 2] + v[i + 3][j + 2] +
              v[i][j - 1] + v[i][j + 3] + v[i + 2][j - 1] + v[i + 2][j + 3] ==
          8)
        sq++;
    }
  }

  // 3x3 square
  if (v[0][1] + v[0][3] + v[0][5] + v[1][0] + v[1][6] + v[3][0] + v[3][6] +
          v[5][0] + v[5][6] + v[6][1] + v[6][3] + v[6][5] ==
      12)
    sq++;
  cout << 24 - st << ' ' << sq;
  return 0;
}