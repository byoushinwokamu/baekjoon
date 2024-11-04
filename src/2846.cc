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
  int n, a = 0, g = 0;
  vector<int> p(1000);
  cin >> n >> p[0];
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    if (p[i - 1] < p[i]) {
      g = max(g, p[i] - p[a]);
    } else {
      a = i;
    }
  }
  cout << g;

  return 0;
}
