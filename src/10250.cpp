#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int h, w, n;
    cin >> h >> w >> n;
    cout << (n % h == 0 ? h : n % h)
         << (n / h + (n % h == 0 ? 0 : 1) < 10 ? "0" : "")
         << n / h + (n % h == 0 ? 0 : 1) << "\n";
  }

  return 0;
}