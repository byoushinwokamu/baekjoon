// BOJ 14568
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

  int cnt = 0;
  for (int th = 2; th < n; th += 2) {
    for (int yh = 1; th + yh < n; yh++) {
      int ng = n - th - yh;
      if (ng < yh + 2)
        continue;
      cnt++;
      cout << th << ' ' << yh << ' ' << ng << endl;
    }
  }
  cout << cnt;

  return 0;
}
