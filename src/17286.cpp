#include <cmath>
#include <iostream>

using namespace std;

double x[4], y[4];

double distance(int a, int b) {
  return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  for (int i = 0; i < 4; i++)
    cin >> x[i] >> y[i];
  double mindis = 1000000;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      if (i == j)
        continue;
      for (int k = 1; k <= 3; k++) {
        if (i == k || j == k)
          continue;
        double dis = distance(0, i) + distance(i, j) + distance(j, k);
        mindis = mindis < dis ? mindis : dis;
      }
    }
  }
  cout << (int)mindis;
  return 0;
}