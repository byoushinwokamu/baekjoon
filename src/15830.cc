#include <algorithm>
#include <cmath>
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
  double v, w, d;
  cin >> v >> w >> d;
  int cnt = 0;
  while (d > 0) {
    double t = w / v;
    d -= 5 * t * t;
    if (d > 0)
      cnt++;
    w *= 1.25;
  }
  cout << cnt;

  return 0;
}
