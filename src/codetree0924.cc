#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> v[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) { // start point iteration
      int dlen1 = 1, dlen2 = 1;
      bool valid = true;
      for (dlen1 = 1; valid; dlen1++)
    }
  }

  return 0;
}