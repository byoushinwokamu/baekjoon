#include <cmath>
#include <iostream>

using namespace std;
double getangle(double a, double b) {
  double t = a > b ? a - b : b - a;
  return t < 180 ? t : 360 - t;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  double h, m, s;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    cin >> h >> m >> s;
    m += s / 60, h += m / 60;
    h *= 30, m *= 6, s *= 6;
    double minang = getangle(h, m);
    double ang = getangle(h, s);
    minang = minang < ang ? minang : ang;
    ang = getangle(m, s);
    minang = minang < ang ? minang : ang;
    cout << fixed << minang << '\n';
  }

  return 0;
}