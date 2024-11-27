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
  int n, m = 0;
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
      m = max(m, 10000 + 1000 * a);
    else if (a == b)
      m = max(m, 1000 + a * 100);
    else if (c == b)
      m = max(m, 1000 + c * 100);
    else if (a == c)
      m = max(m, 1000 + a * 100);
    else
      m = max(m, 100 * max({a, b, c}));
  }
  cout << m;

  return 0;
}
