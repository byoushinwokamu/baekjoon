#include <algorithm>
#include <cmath>
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
  int n, a = 0;
  bool apush = false;
  double aa;
  cin >> n;
  while (n--) {
    cin >> aa;
    if (!apush && aa > 0)
      a += ceil(aa), apush = true;
    else
      a += floor(aa);
  }
  cout << a;

  return 0;
}
