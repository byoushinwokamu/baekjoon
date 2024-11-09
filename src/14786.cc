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

double a, b, c;

double f(double x) { return a * x + b * sin(x) - c; }
double df(double x) { return a + b * cos(x); }

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  double x, nx, dx = 1e-15;
  double e, ea = 1e-10;
  cin >> a >> b >> c;

  x = c / a;
  do {
    nx = x - f(x) / df(x);
    e = abs(nx - x);
    x = nx;
  } while (e > ea);

  cout << fixed;
  cout.precision(12);
  cout << nx;

  return 0;
}
