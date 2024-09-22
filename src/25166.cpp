#include <iostream>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int s, m;
  cin >> s >> m;
  for (int i = 0; i < 10; i++) {
    if (1 << i)
      s &= !(1 << i);
  }

  return 0;
}