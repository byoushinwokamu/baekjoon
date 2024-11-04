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
  int n, in;
  vector<int> a;

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> in, a.push_back(in);

  sort(a.begin(), a.end());
  int md = 0;
  int mdi = 0;
  for (auto i = a.begin() + 1; i != a.end(); i++) {
    if (*i - *(i - 1) == 1)
      continue;
    if (md < (*i - *(i - 1)) / 2) {
      md = (*i - *(i - 1)) / 2;
      mdi = *(i - 1) + md;
    }
  }
  cout << (mdi > 1 ? mdi : -1);

  return 0;
}
