// BOJ 2774
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
  char str[11];
  int t, x;
  cin >> t;
  while (t--) {
    cin >> x;
    sprintf(str, "%d", x);
    vector<bool> v(10);
    for (int i = 0; str[i]; i++)
      v[str[i] - '0'] = true;
    int c = 0;
    for (auto a : v)
      if (a)
        c++;
    cout << c << '\n';
  }

  return 0;
}
