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
  int l, n, a, b;
  cin >> l >> n;
  vector<int> roll(l + 1);
  vector<int> exp(n);
  int eee = 0;
  vector<int> rea(n);
  int rrr = 0;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    exp[i] = b - a + 1;
    if (exp[i] > exp[eee])
      eee = i;

    for (int j = a; j <= b; j++)
      if (roll[j] == 0)
        roll[j] = 1, rea[i]++;
    if (rea[i] > rea[rrr])
      rrr = i;
  }
  cout << eee + 1 << endl << rrr + 1;

  return 0;
}
