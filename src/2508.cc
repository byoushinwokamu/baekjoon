#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<string> box;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t, r, c;
  cin >> t;
  while (t--) {
    int st = 0;
    box.clear();
    cin >> r >> c;
    box.resize(r);
    for (int i = 0; i < r; i++) {
      cin >> box[i];
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (box[i][j] != 111)
          continue;
        if (i > 0 && i < r - 1)
          if (box[i - 1][j] == 118 && box[i + 1][j] == 94)
            st++;
        if (j > 0 && j < c - 1)
          if (box[i][j - 1] == 62 && box[i][j + 1] == 60)
            st++;
      }
    }
    cout << st << '\n';
  }

  return 0;
}
