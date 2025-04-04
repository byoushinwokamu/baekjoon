// BOJ 10188
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
  int t;
  cin >> t;
  while (t--) {
    int r, c;
    cin >> c >> r;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++)
        cout << 'X';
      cout << '\n';
    }
    cout << '\n';
  }

  return 0;
}
