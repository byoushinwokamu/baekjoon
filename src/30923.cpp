#include <cmath>
#include <iostream>

using namespace std;

long long h[32769];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    if (i == 0)
      s += h[0];
    else
      s += abs(h[i] - h[i - 1]);
    s += 2 * h[i] + 2;
  }
  s += h[n - 1];
  cout << s;

  return 0;
}