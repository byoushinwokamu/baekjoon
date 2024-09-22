#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int res = 1;
  for (int i = n; i > n - k; i--)
    res *= i;
  for (int i = k; i > 0; i--)
    res /= i;
  cout << res;

  return 0;
}