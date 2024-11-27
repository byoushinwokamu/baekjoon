#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

ll g, t, a, d, y, i;
ll to, le;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  while (true) {
    cin >> g >> t >> a >> d;
    if (g == -1)
      break;
    to = g * a + d;
    for (i = 0; i < 63; i++) {
      if (to == ((ll)1 << i))
        break;
      if (g * a + d < ((ll)1 << i)) {
        to = ((ll)1 << i);
        break;
      }
    }
    le = t * (t - 1) / 2 * g;
    y = d > 0 ? (to - (g * a + d)) : 0;
    to--;

    cout << g << '*' << a << '/' << t << '+' << d << '=';
    cout << to + le << '+' << y << '\n';
  }

  return 0;
}