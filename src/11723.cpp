#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int s = 0, m, param;
  string op;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> op;
    if (!op.compare("add")) {
      cin >> param;
      s |= (1 << param);
    } else if (!op.compare("remove")) {
      cin >> param;
      s &= ~(1 << param);
    } else if (!op.compare("check")) {
      cin >> param;
      cout << (s & (1 << param) ? 1 : 0) << '\n';
    } else if (!op.compare("toggle")) {
      cin >> param;
      s ^= (1 << param);
    } else if (!op.compare("all"))
      s = INT32_MAX;
    else
      s = 0;
  }

  return 0;
}