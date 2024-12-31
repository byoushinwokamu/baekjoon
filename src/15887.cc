#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int n;
vector<int> c;
int opn = 0;
vector<pp> op;

void reverse(int l, int r) {
  int t;
  for (int i = 0; i < (r - l + 1) / 2; i++) {
    t = c[l + i];
    c[l + i] = c[r - i];
    c[r - i] = t;
  }
}

int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> n;
  c.resize(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];

  for (int i = 0; i < n; i++) {
    if (c[i] != i + 1) {
      for (int j = i + 1; j < n; j++)
        if (c[j] == i + 1) {
          opn++, op.push_back({i, j}), reverse(i, j);
          break;
        }
    }
  }

  cout << opn << '\n';
  for (auto p : op) {
    cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
  }

  return 0;
}
