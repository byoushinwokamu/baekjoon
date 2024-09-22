#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  vector<long long> v;
  int n, m;
  cin >> n >> m;

  long long a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  // sort(v.begin(), v.end());

  long long ll = 0, rr = 1073741824, mid, len, res;
  while (ll <= rr) {
    mid = (ll + rr) / 2;
    len = 0;
    for (int i = 0; i < n; i++)
      len += (v[i] > mid) ? (v[i] - mid) : 0;
    if (len > m) { // 많이 캤으니까 높혀보기
      res = mid;
      ll = mid + 1;
    } else if (len == m) {
      res = mid;
      break;
    } else { // (len < m) 부족하니까 낮추기
      rr = mid - 1;
    }
  }
  cout << res;
  return 0;
}