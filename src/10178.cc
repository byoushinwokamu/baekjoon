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
  int t, c, v;
  cin >> t;
  while (t--) {
    cin >> c >> v;
    cout << "You get " << c / v << " piece(s) and your dad gets " << c % v
         << " piece(s).\n";
  }

  return 0;
}
