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
  int n;
  cin >> n;
  cout << (ll)(n - 1) * (n - 2) + (n - 1) << '\n';
  for (int i = 2; i <= n; i++) {
    cout << 1 << ' ' << i << '\n';
  }

  return 0;
}
