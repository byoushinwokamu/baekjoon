#include <cmath>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  double w, h;
  int n;
  double len = 0;
  cin >> h >> w >> n;
  for (int i = 1; i <= (n - 1) / 2; i++) {
    double hh = (double)h / n * i;
    len += w * (h / 2 - hh) / (h / 2);
  }
  cout << fixed << len * 2;

  return 0;
}