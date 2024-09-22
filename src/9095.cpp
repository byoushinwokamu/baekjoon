#include <iostream>

using namespace std;

int ways[15];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int t, n;
  cin >> t;

  ways[1] = 1;
  ways[2] = 2;
  ways[3] = 4;
  for (int i = 4; i < 15; i++)
    ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];

  for (int i = 0; i < t; i++) {
    cin >> n;
    cout << ways[n] << '\n';
  }

  return 0;
}