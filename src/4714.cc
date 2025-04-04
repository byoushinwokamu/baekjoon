// BOJ 4714
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
  double x = 0;
  cout << fixed;
  cout.precision(2);
  while (true) {
    cin >> x;
    if (x < 0)
      break;
    cout << "Objects weighing " << x << " on Earth will weigh " << (x * 0.167)
         << " on the moon.\n";
  }

  return 0;
}
