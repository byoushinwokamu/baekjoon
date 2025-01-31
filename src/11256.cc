// BOJ 11256
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
  int t;
  cin >> t;
  while (t--) {
    int j, n;
    cin >> j >> n;
    vector<int> box(n);
    for (int i = 0; i < n; i++) {
      int r, c;
      cin >> r >> c;
      box[i] = r * c;
    }
    sort(box.begin(), box.end(), greater<int>());
    int k = 0, c = 0;
    for (auto i = box.begin(); k < j; i++)
      k += *i, c++;
    cout << c << '\n';
  }

  return 0;
}
