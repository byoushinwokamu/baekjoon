#include <iostream>

using namespace std;

int pow2(int a) {
  int res = 1;
  for (int i = 0; i < a; i++)
    res *= 2;
  return res;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, r, c;
  cin >> n >> r >> c;

  int result = 0;
  while (n-- > 1) {
    if (c >= pow2(n)) {
      result += pow2(2 * n);
      c -= pow2(n);
    }
    if (r >= pow2(n)) {
      result += pow2(2 * n + 1);
      r -= pow2(n);
    }
  }
  cout << result + r * 2 + c;
  return 0;
}