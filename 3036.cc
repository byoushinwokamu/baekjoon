#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n, r0, r, gg;
  cin >> n >> r0;
  for (int i = 1; i < n; i++) {
    cin >> r;
    gg = __gcd(r0, r);
    cout << r0 / gg << '/' << r / gg << '\n';
  }
  return 0;
}