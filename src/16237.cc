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
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;

  int gb = e + 1, no = 5;
  while (a + b + c + d > 0) {
    if (no == 0)
      gb++, no = 5;

    if (no > 3 && d > 0) {
      no -= 4, d--;
      continue;
    } else if (no > 2 && c > 0) {
      no -= 3, c--;
      continue;
    } else if (no > 1 && b > 0) {
      no -= 2, b--;
      continue;
    } else if (no > 0 && a > 0) {
      no -= 1, a--;
      continue;
    } else
      gb++, no = 5;
  }
  cout << gb - (no == 5 ? 1 : 0);

  return 0;
}
