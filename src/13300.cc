#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int stu[2][7];

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n, k, s, y, r = 0;
  cin >> n >> k;
  while (n--) {
    cin >> s >> y;
    stu[s][y]++;
  }
  for (int i = 0; i < 2; i++)
    for (int j = 1; j < 7; j++)
      if (stu[i][j])
        r += (stu[i][j] - 1) / k + 1;

  cout << r;
  return 0;
}