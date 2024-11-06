#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n = 0, m = 0, i;
  string s;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == ':')
      break;
    n *= 10;
    n += s[i] - '0';
  }
  for (i++; i < s.length(); i++) {
    m *= 10;
    m += s[i] - '0';
  }
  for (int i = max(n, m); i > 1; i--) {
    if (n % i == 0 && m % i == 0)
      n /= i, m /= i;
  }
  cout << n << ':' << m;

  return 0;
}
