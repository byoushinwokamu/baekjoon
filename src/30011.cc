#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define first fi
#define second se
typedef long long ll;

using namespace std;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll res = 180 * (a[0] - 2);
  for (int i = 1; i < n; i++)
    res += 180 * a[i];
  cout << res;

  return 0;
}