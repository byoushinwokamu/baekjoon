#include <iostream>

using namespace std;

// ab mod z = (a mod z)(b mod z) mod z

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  long long a, b, c;
  cin >> a >> b >> c;
  a %= c;
  long long res = 1;
  if (b == 0) {
    cout << a;
    return 0;
  }
  while (b > 0) {
    if (b % 2 == 1)
      res *= a;
    res %= c;
    a = (a * a) % c;
    b /= 2;
  }

  cout << res;

  return 0;
}