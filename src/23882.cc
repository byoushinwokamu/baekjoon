// BOJ 23882
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

vector<int> a;
int n, k;
int cnt;

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = n - 1; i >= 1; i--) {
    int mxm = a[i], mxmidx = i;
    for (int j = 0; j < i; j++)
      if (mxm < a[j])
        mxm = a[j], mxmidx = j;
    if (mxm != a[i])
      a[mxmidx] = a[i], a[i] = mxm, cnt++;
    if (cnt == k) {
      for (auto aa : a)
        cout << aa << ' ';
      return 0;
    }
  }
  cout << -1;

  return 0;
}
