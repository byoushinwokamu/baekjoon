#include <iostream>

using namespace std;

bool sieve[1000001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;

  sieve[1] = true;
  for (int i = 2; i <= 1000000; i++) {
    if (sieve[i])
      continue;
    for (int j = 2; i * j <= 1000000; j++)
      sieve[i * j] = true;
  }
  for (int i = m; i <= n; i++)
    if (!sieve[i])
      cout << i << '\n';
  return 0;
}