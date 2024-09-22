#include <iostream>

using namespace std;

int train[100001];
char pattern[1050000];
int cnt;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n, m, op, i, x;
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    cin >> op >> i;
    switch (op) {
    case 1:
      cin >> x;
      train[i] |= 1 << (x - 1);
      break;
    case 2:
      cin >> x;
      train[i] &= !(1 << (x - 1));
      break;
    case 3:
      train[i] <<= 1;
      train[i] &= !(1 << 20);
      break;
    case 4:
      train[i] >>= 1;
    }
  }
  // cout << "res" << endl;
  for (int i = 1; i <= n; i++) {
    // cout << train[i] << endl;
    if (!pattern[train[i]]++)
      cnt++;
  }

  cout << cnt;

  return 0;
}