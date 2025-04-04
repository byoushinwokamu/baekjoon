// BOJ 3460
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
    for (int i = 0; n; i++) {
      if (n & 1)
        cout << i << ' ';
      n >>= 1;
    }
    cout << '\n';
  }

  return 0;
}
