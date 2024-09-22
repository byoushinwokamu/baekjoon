#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;
  while (a + b + c > 0) {
    a *= a, b *= b, c *= c;
    if (a + b == c || b + c == a || c + a == b)
      cout << "right\n";
    else
      cout << "wrong\n";
    cin >> a >> b >> c;
  }

  return 0;
}