#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  long long has = 0;
  int l;
  char str[51];
  cin >> l >> str;
  long long m = 1234567891;
  long long r = 31;
  long long rp = 1;
  for (int i = 0; i < l; i++) {
    has += ((long long)str[i] - 96) * rp;
    has %= m;
    rp = rp * r % m;
  }
  cout << has;

  return 0;
}