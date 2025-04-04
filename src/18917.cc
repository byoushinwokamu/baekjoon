// BOJ 18917
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
  int m, op, x, exor = 0;
  ll summ = 0;
  cin >> m;
  while (m--) {
    cin >> op;
    if (op < 3)
      cin >> x;
    switch (op) {
    case 1:
      summ += x, exor ^= x;
      break;
    case 2:
      summ -= x, exor ^= x;
      break;
    case 3:
      cout << summ << '\n';
      break;
    case 4:
      cout << exor << '\n';
    }
  }

  return 0;
}
