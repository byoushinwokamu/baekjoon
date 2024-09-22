#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  long long people[15][14];
  for (int i = 0; i < 14; i++) {
    people[0][i] = i + 1;
  }
  for (int i = 1; i < 15; i++) {
    people[i][0] = 1;
    for (int j = 1; j < 14; j++)
      people[i][j] = people[i][j - 1] + people[i - 1][j];
  }
  for (int tt = 0; tt < t; tt++) {
    int k, n;
    cin >> k >> n;
    cout << people[k][n - 1] << '\n';
  }

  return 0;
}