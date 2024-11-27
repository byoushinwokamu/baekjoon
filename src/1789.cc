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
  unsigned s, n = 0, a = 0;
  cin >> s;
  if (s == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= s; i++) {
    a += i;
    if (a > s || a < i) {
      cout << i - 1;
      return 0;
    }
  }

  return 0;
}
