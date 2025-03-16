// BOJ 3649
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
  int x, n;
  vector<int> lego;
  cin >> x;
  while (!cin.eof()) {
    x *= 10'000'000;
    cin >> n;
    lego.resize(n);
    for (int i = 0; i < n; i++)
      cin >> lego[i];
    sort(lego.begin(), lego.end());

    bool yes = false;
    int f = 0, r = n - 1, hole = 0;
    while (f < r) {
      hole = lego[f] + lego[r];
      if (hole == x) {
        cout << "yes " << lego[f] << ' ' << lego[r] << '\n';
        break;
      } else if (hole < x)
        f++;
      else if (hole > x)
        r--;
    }
    if (hole != x)
      cout << "danger\n";

    cin >> x;
  }

  return 0;
}
