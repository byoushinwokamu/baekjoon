#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int a = 1, b = 1, c = 1, t;
  cin >> a >> b >> c;
  while (a + b + c > 0) {
    if (a < b) {
      t = a;
      a = b;
      b = t;
    }
    if (b < c) {
      t = b;
      b = c;
      c = t;
    }
    if (a < b) {
      t = a;
      a = b;
      b = t;
    }
    if (a >= b + c)
      cout << "Invalid\n";
    else {
      if (a == b && b == c)
        cout << "Equilateral\n";
      else if (a == b || b == c || c == a)
        cout << "Isosceles\n";
      else
        cout << "Scalene\n";
    }
    cin >> a >> b >> c;
  }
  return 0;
}