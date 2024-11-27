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
  int n;
  cin >> n;
  vector<int> price(n);
  for (int i = 0; i < n; i++)
    cin >> price[i];

  int gj = 0, si = 0;
  for (auto it = price.rbegin(); it != price.rend(); it++) {
    if (gj < *it)
      gj = *it;
    else
      si += gj - *it;
  }
  cout << si;

  return 0;
}
