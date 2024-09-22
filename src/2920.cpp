#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int state = 0; // + ascending 0 mixed - descending
  int n, m;
  cin >> n >> m;
  state = m - n;
  for (int i = 2; i < 8; i++) {
    n = m;
    cin >> m;
    if (state * (m - n) < 0) {
      state = 0;
      break;
    }
  }
  if (state > 0)
    cout << "ascending";
  else if (state < 0)
    cout << "descending";
  else
    cout << "mixed";

  return 0;
}