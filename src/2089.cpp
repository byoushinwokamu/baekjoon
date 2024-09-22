#include <cmath>
#include <iostream>

using namespace std;
bool res[100];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  long long n, i = 1, t = 1, scale = 1; // i는 이진수 자릿수
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  if (n < 0)
    i = 2, t = 2, scale = 2, n = -n;
  while (t < n) {
    scale *= 4;
    t += scale;
    i += 2;
  }
  n = t - n;
  int j = 0;
  while (n > 0) {
    res[j++] = n % 2 == 1;
    n /= 2;
  }
  for (int r = 0; r < i; r++)
    cout << (res[i - r - 1] != (r % 2 == 0) ? 1 : 0);

  return 0;
}