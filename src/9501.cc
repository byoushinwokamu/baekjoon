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
  int t, n, d;
  int v, f, c;
  cin >> t;
  while (t--) {
    int cnt = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
      cin >> v >> f >> c;
      v *f / c >= d ? cnt++ : cnt;
    }
    cout << cnt << '\n';
  }

  return 0;
}
