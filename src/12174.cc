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
  int t, b, a;
  string s;
  char c;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    c = 0, a = 0;
    cin >> b >> s;
    while (b--) {
      for (int i = 0; i < 8; i++) {
        c <<= 1;
        c |= s[a + i] == 'I' ? 1 : 0;
      }
      a += 8;
      cout << c;
    }
    cout << '\n';
  }

  return 0;
}
