#include <cmath>
#include <iostream>

using namespace std;

int x[100];
int y[100];

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n, r, maxcnt = 0, maxx, maxy;
  cin >> n >> r;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  for (int i = -100; i <= 100; i++) {
    for (int j = -100; j <= 100; j++) {
      int cnt = 0;
      for (int k = 0; k < n; k++) {
        if (dis(i, j, x[k], y[k]) <= r)
          cnt++;
      }
      if (maxcnt < cnt) {
        maxcnt = cnt;
        maxx = i;
        maxy = j;
      }
    }
  }
  cout << maxx << " " << maxy;

  return 0;
}