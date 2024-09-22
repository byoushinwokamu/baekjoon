#include <iostream>

using namespace std;

long long fac[21];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  fac[0] = 1;
  fac[1] = 1;
  for (int i = 2; i <= 20; i++)
    fac[i] = fac[i - 1] * i;

  long long n;
  cin >> n;
  if (n == 0) {
    cout << "NO";
    return 0;
  }
  for (int i = 20; i >= 0; i--) {
    n -= n >= fac[i] ? fac[i] : 0;
  }
  cout << (n == 0 ? "YES" : "NO");

  return 0;
}