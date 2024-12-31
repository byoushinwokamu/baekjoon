#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int h, y;
ll bal = 0;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> h >> y;
  vector<ll> maxbal(y + 1);
  maxbal[0] = h;
  for (int i = 0; i < y; i++) {
    if (i + 1 <= y)
      maxbal[i + 1] = max(maxbal[i + 1], (ll)(maxbal[i] * 1.05));
    if (i + 3 <= y)
      maxbal[i + 3] = max(maxbal[i + 3], (ll)(maxbal[i] * 1.20));
    if (i + 5 <= y)
      maxbal[i + 5] = max(maxbal[i + 5], (ll)(maxbal[i] * 1.35));
  }
  cout << maxbal[y];

  return 0;
}
