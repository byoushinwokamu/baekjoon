// BOJ 22951
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
  int n, k, nk;
  cin >> n >> k;
  nk = n * k;
  vector<int> v(nk);
  for (int i = 0; i < nk; i++) {
    cin >> v[i];
  }
  int cur = 0, cnt = nk;
  while (cnt-- > 1) {
    int step = v[cur];
    v[cur] = 0;
    while (step) {
      if (v[cur++])
        step--;
      cur = (cur == nk ? 0 : cur);
    }
    cur = (cur == 0 ? nk - 1 : cur - 1);
  }
  for (cur = 0; !v[cur]; cur++)
    ;
  cout << (cur / k + 1) << ' ' << v[cur];

  return 0;
}
