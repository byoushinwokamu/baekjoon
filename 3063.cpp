#include <iostream>

using namespace std;

int makerange(int l, int r, int target) {
  if (l > target)
    return l;
  if (r < target)
    return r;
  return target;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int testcase = 0; testcase < t; testcase++) {
    int x[4], y[4];
    int siz, fuc;
    for (int i = 0; i < 4; i++)
      cin >> x[i] >> y[i];
    siz = (x[1] - x[0]) * (y[1] - y[0]);
    x[2] = makerange(x[0], x[1], x[2]);
    x[3] = makerange(x[0], x[1], x[3]);
    y[2] = makerange(y[0], y[1], y[2]);
    y[3] = makerange(y[0], y[1], y[3]);
    fuc = (x[3] - x[2]) * (y[3] - y[2]);
    cout << siz - fuc << '\n';
  }

  return 0;
}