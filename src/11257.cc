// BOJ 11257
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
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d, s = 0;
    bool pass = true;
    cin >> a >> b >> c >> d;
    cout << a << ' ';
    if (b < 11)
      pass = false;
    if (c < 8)
      pass = false;
    if (d < 12)
      pass = false;
    if (b + c + d < 55)
      pass = false;
    cout << b + c + d << (pass ? " PASS\n" : " FAIL\n");
  }

  return 0;
}
