#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, res = 0;
  for (int i = 0; i < 5; i++) {
    cin >> n;
    res += n * n;
  }
  cout << res % 10;

  return 0;
}