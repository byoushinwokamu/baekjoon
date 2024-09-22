#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  int a1 = a, b1 = b;
  int t;
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  cout << a << "\n";
  cout << a1 * b1 / a;

  return 0;
}