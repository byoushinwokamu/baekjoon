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
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pp> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i].fi >> p[i].se;
  }

  return 0;
}
