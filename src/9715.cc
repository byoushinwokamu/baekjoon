#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int t, r, c;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    cin >> r >> c;
    vector<string> v(r);
    int area = 0;
    for (int i = 0; i < r; i++) {
      cin >> v[i];
    }

    for (int i = 0; i < r; i++) {
      // view from outside
      for (int j = 0; j < c; j++) {
        // view from above & below
        area += (v[i][j] - '0') ? 2 : 0;
        // view from left/right side
        if (j == 0)
          area += v[i][0] - '0' + v[i][c - 1] - '0';
        if (j < c - 1)
          area += abs((v[i][j] - '0') - (v[i][j + 1] - '0'));
        // view from up/down side
        if (i == 0)
          area += v[0][j] - '0' + v[r - 1][j] - '0';
        if (i < r - 1)
          area += abs((v[i][j] - '0') - (v[i + 1][j] - '0'));
      }
    }
    cout << area << '\n';
  }
  return 0;
}