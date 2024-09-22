#include <cmath>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, w, h;
  cin >> n >> w >> h;
  double len = sqrt(w * w + h * h), sn;
  for (int i = 0; i < n; i++) {
    cin >> sn;
    cout << (len >= sn ? "DA\n" : "NE\n");
  }

  return 0;
}