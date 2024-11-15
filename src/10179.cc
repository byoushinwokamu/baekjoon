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
  double p;
  cin >> t;
  while (t--) {
    cin >> p;
    cout << fixed;
    cout.precision(2);
    cout << '$' << p * 0.8 << '\n';
  }

  return 0;
}
