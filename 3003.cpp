#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int k, q, r, b, kn, p;
  cin >> k >> q >> r >> b >> kn >> p;
  cout << 1 - k << " " << 1 - q << " " << 2 - r << " " << 2 - b << " " << 2 - kn
       << " " << 8 - p;

  return 0;
}