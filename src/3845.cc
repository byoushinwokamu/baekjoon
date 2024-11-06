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
  int nx, ny;
  double w;
  cin >> nx >> ny >> w;

  while (nx + ny + w != 0) {
    vector<double> xi(nx), yi(ny);
    for (int i = 0; i < nx; i++)
      cin >> xi[i];
    for (int i = 0; i < ny; i++)
      cin >> yi[i];
    sort(xi.begin(), xi.end());
    sort(yi.begin(), yi.end());

    bool x = true, y = true;

    if (xi[0] * 2 > w || (75 - xi[nx - 1]) * 2 > w)
      x = false;
    else
      for (int i = 1; i < nx; i++) {
        if (xi[i] - xi[i - 1] > w)
          x = false;
      }

    if (yi[0] * 2 > w || (100 - yi[ny - 1]) * 2 > w)
      y = false;
    else
      for (int i = 1; i < ny; i++) {
        if (yi[i] - yi[i - 1] > w)
          y = false;
      }

    cout << ((x && y) ? "YES\n" : "NO\n");
    cin >> nx >> ny >> w;
  }

  return 0;
}
